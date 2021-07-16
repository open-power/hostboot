/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00000.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

#ifndef __PROC_REG00000_H_
#define __PROC_REG00000_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[INT_VC_EASC_FLUSH_CTRL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_EASC_FLUSH_CTRL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_EASC_FLUSH_CTRL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[INT_VC_EASC_FLUSH_CTRL]

//>> GET_[INT_VC_EASC_FLUSH_CTRL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_EASC_FLUSH_CTRL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_EASC_FLUSH_CTRL;
#endif
    return fapi2::getScom(i_target, INT_VC_EASC_FLUSH_CTRL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[INT_VC_EASC_FLUSH_CTRL]

//>> PUT_[INT_VC_EASC_FLUSH_CTRL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_EASC_FLUSH_CTRL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_CTRL));
#endif
    return fapi2::putScom(i_target, INT_VC_EASC_FLUSH_CTRL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[INT_VC_EASC_FLUSH_CTRL]


//>> SET_[INT_VC_EASC_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_EASC_FLUSH_CTRL_POLL_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_VC_EASC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_EASC_FLUSH_CTRL_POLL_VALID]

//>> SET_[INT_VC_EASC_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_CTRL_POLL_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_EASC_FLUSH_CTRL_POLL_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_VC_EASC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_EASC_FLUSH_CTRL_POLL_VALID]

//>> SET_[INT_VC_EASC_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_CTRL));
#endif
    return o_data.setBit<INT_VC_EASC_FLUSH_CTRL_POLL_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_VC_EASC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_EASC_FLUSH_CTRL_POLL_VALID]

//>> CLEAR_[INT_VC_EASC_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_EASC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_CTRL));
#endif
    return o_data.clearBit<INT_VC_EASC_FLUSH_CTRL_POLL_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_VC_EASC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_VC_EASC_FLUSH_CTRL_POLL_VALID]

//>> GET_[INT_VC_EASC_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_VC_EASC_FLUSH_CTRL_POLL_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_VC_EASC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_EASC_FLUSH_CTRL_POLL_VALID]

//>> GET_[INT_VC_EASC_FLUSH_CTRL_POLL_VALID]
static inline bool GET_INT_VC_EASC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_CTRL));
#endif
    return i_data.getBit<INT_VC_EASC_FLUSH_CTRL_POLL_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_VC_EASC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_EASC_FLUSH_CTRL_POLL_VALID]

//>> SET_[INT_VC_EASC_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_EASC_FLUSH_CTRL_RESERVED_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_VC_EASC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_EASC_FLUSH_CTRL_RESERVED_1]

//>> SET_[INT_VC_EASC_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_CTRL_RESERVED_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_EASC_FLUSH_CTRL_RESERVED_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_VC_EASC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_EASC_FLUSH_CTRL_RESERVED_1]

//>> SET_[INT_VC_EASC_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_CTRL));
#endif
    return o_data.setBit<INT_VC_EASC_FLUSH_CTRL_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_VC_EASC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_EASC_FLUSH_CTRL_RESERVED_1]

//>> CLEAR_[INT_VC_EASC_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_EASC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_CTRL));
#endif
    return o_data.clearBit<INT_VC_EASC_FLUSH_CTRL_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_VC_EASC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_VC_EASC_FLUSH_CTRL_RESERVED_1]

//>> GET_[INT_VC_EASC_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_VC_EASC_FLUSH_CTRL_RESERVED_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_VC_EASC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_EASC_FLUSH_CTRL_RESERVED_1]

//>> GET_[INT_VC_EASC_FLUSH_CTRL_RESERVED_1]
static inline bool GET_INT_VC_EASC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_CTRL));
#endif
    return i_data.getBit<INT_VC_EASC_FLUSH_CTRL_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_VC_EASC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_EASC_FLUSH_CTRL_RESERVED_1]

//>> SET_[INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> SET_[INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> SET_[INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_CTRL));
#endif
    return o_data.setBit<INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> CLEAR_[INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_CTRL));
#endif
    return o_data.clearBit<INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> GET_[INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> GET_[INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline bool GET_INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_CTRL));
#endif
    return i_data.getBit<INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> SET_[INT_VC_EASC_FLUSH_CTRL_RESERVED_3_7]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_CTRL_RESERVED_3_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_EASC_FLUSH_CTRL_RESERVED_3_7,
           INT_VC_EASC_FLUSH_CTRL_RESERVED_3_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_VC_EASC_FLUSH_CTRL_RESERVED_3_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_EASC_FLUSH_CTRL_RESERVED_3_7]

//>> SET_[INT_VC_EASC_FLUSH_CTRL_RESERVED_3_7]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_EASC_FLUSH_CTRL_RESERVED_3_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_EASC_FLUSH_CTRL_RESERVED_3_7,
           INT_VC_EASC_FLUSH_CTRL_RESERVED_3_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_VC_EASC_FLUSH_CTRL_RESERVED_3_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_EASC_FLUSH_CTRL_RESERVED_3_7]

//>> GET_[INT_VC_EASC_FLUSH_CTRL_RESERVED_3_7]
static inline fapi2::buffer<uint64_t>& GET_INT_VC_EASC_FLUSH_CTRL_RESERVED_3_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_EASC_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_VC_EASC_FLUSH_CTRL_RESERVED_3_7,
           INT_VC_EASC_FLUSH_CTRL_RESERVED_3_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_VC_EASC_FLUSH_CTRL_RESERVED_3_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_EASC_FLUSH_CTRL_RESERVED_3_7]

//>> PREP_[MCD_BANK0_VGC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_BANK0_VGC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_BANK0_VGC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MCD_BANK0_VGC]

//>> GET_[MCD_BANK0_VGC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_BANK0_VGC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_BANK0_VGC;
#endif
    return fapi2::getScom(i_target, MCD_BANK0_VGC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MCD_BANK0_VGC]

//>> PUT_[MCD_BANK0_VGC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_BANK0_VGC(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return fapi2::putScom(i_target, MCD_BANK0_VGC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MCD_BANK0_VGC]


//>> SET_[MCD_BANK0_VGC_P10_AVAIL_GROUPS]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_P10_AVAIL_GROUPS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_P10_AVAIL_GROUPS,
           MCD_BANK0_VGC_P10_AVAIL_GROUPS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_VGC_P10_AVAIL_GROUPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_P10_AVAIL_GROUPS]

//>> SET_[MCD_BANK0_VGC_P10_AVAIL_GROUPS]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_P10_AVAIL_GROUPS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_P10_AVAIL_GROUPS,
           MCD_BANK0_VGC_P10_AVAIL_GROUPS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_VGC_P10_AVAIL_GROUPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_P10_AVAIL_GROUPS]

//>> GET_[MCD_BANK0_VGC_P10_AVAIL_GROUPS]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_VGC_P10_AVAIL_GROUPS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.extractToRight<MCD_BANK0_VGC_P10_AVAIL_GROUPS,
           MCD_BANK0_VGC_P10_AVAIL_GROUPS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_VGC_P10_AVAIL_GROUPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_P10_AVAIL_GROUPS]

//>> SET_[MCD_BANK0_VGC_RSVD_AVAIL_GROUPS]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_RSVD_AVAIL_GROUPS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_RSVD_AVAIL_GROUPS,
           MCD_BANK0_VGC_RSVD_AVAIL_GROUPS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_VGC_RSVD_AVAIL_GROUPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_RSVD_AVAIL_GROUPS]

//>> SET_[MCD_BANK0_VGC_RSVD_AVAIL_GROUPS]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_RSVD_AVAIL_GROUPS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_RSVD_AVAIL_GROUPS,
           MCD_BANK0_VGC_RSVD_AVAIL_GROUPS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_VGC_RSVD_AVAIL_GROUPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_RSVD_AVAIL_GROUPS]

//>> GET_[MCD_BANK0_VGC_RSVD_AVAIL_GROUPS]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_VGC_RSVD_AVAIL_GROUPS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.extractToRight<MCD_BANK0_VGC_RSVD_AVAIL_GROUPS,
           MCD_BANK0_VGC_RSVD_AVAIL_GROUPS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_VGC_RSVD_AVAIL_GROUPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_RSVD_AVAIL_GROUPS]

//>> SET_[MCD_BANK0_VGC_FAILED_GROUPS]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_FAILED_GROUPS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_FAILED_GROUPS,
           MCD_BANK0_VGC_FAILED_GROUPS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_VGC_FAILED_GROUPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_FAILED_GROUPS]

//>> SET_[MCD_BANK0_VGC_FAILED_GROUPS]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_FAILED_GROUPS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_FAILED_GROUPS,
           MCD_BANK0_VGC_FAILED_GROUPS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_VGC_FAILED_GROUPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_FAILED_GROUPS]

//>> GET_[MCD_BANK0_VGC_FAILED_GROUPS]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_VGC_FAILED_GROUPS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.extractToRight<MCD_BANK0_VGC_FAILED_GROUPS,
           MCD_BANK0_VGC_FAILED_GROUPS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_VGC_FAILED_GROUPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_FAILED_GROUPS]

//>> SET_[MCD_BANK0_VGC_FORCE_RTY_MCD_RATE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_FORCE_RTY_MCD_RATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_FORCE_RTY_MCD_RATE,
           MCD_BANK0_VGC_FORCE_RTY_MCD_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_VGC_FORCE_RTY_MCD_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_FORCE_RTY_MCD_RATE]

//>> SET_[MCD_BANK0_VGC_FORCE_RTY_MCD_RATE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_FORCE_RTY_MCD_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_FORCE_RTY_MCD_RATE,
           MCD_BANK0_VGC_FORCE_RTY_MCD_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_VGC_FORCE_RTY_MCD_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_FORCE_RTY_MCD_RATE]

//>> GET_[MCD_BANK0_VGC_FORCE_RTY_MCD_RATE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_VGC_FORCE_RTY_MCD_RATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.extractToRight<MCD_BANK0_VGC_FORCE_RTY_MCD_RATE,
           MCD_BANK0_VGC_FORCE_RTY_MCD_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_VGC_FORCE_RTY_MCD_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_FORCE_RTY_MCD_RATE]

//>> SET_[MCD_BANK0_VGC_4X4_MODE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_4X4_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_4X4_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_VGC_4X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_4X4_MODE]

//>> SET_[MCD_BANK0_VGC_4X4_MODE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_4X4_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_4X4_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_VGC_4X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_4X4_MODE]

//>> SET_[MCD_BANK0_VGC_4X4_MODE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_4X4_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.setBit<MCD_BANK0_VGC_4X4_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_VGC_4X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_4X4_MODE]

//>> CLEAR_[MCD_BANK0_VGC_4X4_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_VGC_4X4_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.clearBit<MCD_BANK0_VGC_4X4_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_VGC_4X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_VGC_4X4_MODE]

//>> GET_[MCD_BANK0_VGC_4X4_MODE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_VGC_4X4_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.extractToRight<MCD_BANK0_VGC_4X4_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_VGC_4X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_4X4_MODE]

//>> GET_[MCD_BANK0_VGC_4X4_MODE]
static inline bool GET_MCD_BANK0_VGC_4X4_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.getBit<MCD_BANK0_VGC_4X4_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_VGC_4X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_4X4_MODE]

//>> SET_[MCD_BANK0_VGC_HANG_POLL_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_HANG_POLL_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_HANG_POLL_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_VGC_HANG_POLL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_HANG_POLL_ENABLE]

//>> SET_[MCD_BANK0_VGC_HANG_POLL_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_HANG_POLL_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_HANG_POLL_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_VGC_HANG_POLL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_HANG_POLL_ENABLE]

//>> SET_[MCD_BANK0_VGC_HANG_POLL_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_HANG_POLL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.setBit<MCD_BANK0_VGC_HANG_POLL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_VGC_HANG_POLL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_HANG_POLL_ENABLE]

//>> CLEAR_[MCD_BANK0_VGC_HANG_POLL_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_VGC_HANG_POLL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.clearBit<MCD_BANK0_VGC_HANG_POLL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_VGC_HANG_POLL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_VGC_HANG_POLL_ENABLE]

//>> GET_[MCD_BANK0_VGC_HANG_POLL_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_VGC_HANG_POLL_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.extractToRight<MCD_BANK0_VGC_HANG_POLL_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_VGC_HANG_POLL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_HANG_POLL_ENABLE]

//>> GET_[MCD_BANK0_VGC_HANG_POLL_ENABLE]
static inline bool GET_MCD_BANK0_VGC_HANG_POLL_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.getBit<MCD_BANK0_VGC_HANG_POLL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_VGC_HANG_POLL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_HANG_POLL_ENABLE]

//>> SET_[MCD_BANK0_VGC_RND_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_RND_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_RND_BACKOFF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_VGC_RND_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_RND_BACKOFF_ENABLE]

//>> SET_[MCD_BANK0_VGC_RND_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_RND_BACKOFF_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_RND_BACKOFF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_VGC_RND_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_RND_BACKOFF_ENABLE]

//>> SET_[MCD_BANK0_VGC_RND_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_RND_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.setBit<MCD_BANK0_VGC_RND_BACKOFF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_VGC_RND_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_RND_BACKOFF_ENABLE]

//>> CLEAR_[MCD_BANK0_VGC_RND_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_VGC_RND_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.clearBit<MCD_BANK0_VGC_RND_BACKOFF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_VGC_RND_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_VGC_RND_BACKOFF_ENABLE]

//>> GET_[MCD_BANK0_VGC_RND_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_VGC_RND_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.extractToRight<MCD_BANK0_VGC_RND_BACKOFF_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_VGC_RND_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_RND_BACKOFF_ENABLE]

//>> GET_[MCD_BANK0_VGC_RND_BACKOFF_ENABLE]
static inline bool GET_MCD_BANK0_VGC_RND_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.getBit<MCD_BANK0_VGC_RND_BACKOFF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_VGC_RND_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_RND_BACKOFF_ENABLE]

//>> SET_[MCD_BANK0_VGC_DROP_PRIORITY_MODE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_DROP_PRIORITY_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_DROP_PRIORITY_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_VGC_DROP_PRIORITY_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_DROP_PRIORITY_MODE]

//>> SET_[MCD_BANK0_VGC_DROP_PRIORITY_MODE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_DROP_PRIORITY_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_DROP_PRIORITY_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_VGC_DROP_PRIORITY_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_DROP_PRIORITY_MODE]

//>> SET_[MCD_BANK0_VGC_DROP_PRIORITY_MODE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_DROP_PRIORITY_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.setBit<MCD_BANK0_VGC_DROP_PRIORITY_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_VGC_DROP_PRIORITY_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_DROP_PRIORITY_MODE]

//>> CLEAR_[MCD_BANK0_VGC_DROP_PRIORITY_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_VGC_DROP_PRIORITY_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.clearBit<MCD_BANK0_VGC_DROP_PRIORITY_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_VGC_DROP_PRIORITY_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_VGC_DROP_PRIORITY_MODE]

//>> GET_[MCD_BANK0_VGC_DROP_PRIORITY_MODE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_VGC_DROP_PRIORITY_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.extractToRight<MCD_BANK0_VGC_DROP_PRIORITY_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_VGC_DROP_PRIORITY_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_DROP_PRIORITY_MODE]

//>> GET_[MCD_BANK0_VGC_DROP_PRIORITY_MODE]
static inline bool GET_MCD_BANK0_VGC_DROP_PRIORITY_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.getBit<MCD_BANK0_VGC_DROP_PRIORITY_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_VGC_DROP_PRIORITY_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_DROP_PRIORITY_MODE]

//>> SET_[MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE]

//>> SET_[MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE]

//>> SET_[MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.setBit<MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE]

//>> CLEAR_[MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.clearBit<MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE]

//>> GET_[MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.extractToRight<MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE]

//>> GET_[MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE]
static inline bool GET_MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.getBit<MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE]

//>> SET_[MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE]

//>> SET_[MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE]

//>> SET_[MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.setBit<MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE]

//>> CLEAR_[MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.clearBit<MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE]

//>> GET_[MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.extractToRight<MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE]

//>> GET_[MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE]
static inline bool GET_MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.getBit<MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE]

//>> SET_[MCD_BANK0_VGC_P8MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_P8MODE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_P8MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_VGC_P8MODE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_P8MODE_ENABLE]

//>> SET_[MCD_BANK0_VGC_P8MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_P8MODE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_P8MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_VGC_P8MODE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_P8MODE_ENABLE]

//>> SET_[MCD_BANK0_VGC_P8MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_P8MODE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.setBit<MCD_BANK0_VGC_P8MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_VGC_P8MODE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_P8MODE_ENABLE]

//>> CLEAR_[MCD_BANK0_VGC_P8MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_VGC_P8MODE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.clearBit<MCD_BANK0_VGC_P8MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_VGC_P8MODE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_VGC_P8MODE_ENABLE]

//>> GET_[MCD_BANK0_VGC_P8MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_VGC_P8MODE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.extractToRight<MCD_BANK0_VGC_P8MODE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_VGC_P8MODE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_P8MODE_ENABLE]

//>> GET_[MCD_BANK0_VGC_P8MODE_ENABLE]
static inline bool GET_MCD_BANK0_VGC_P8MODE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.getBit<MCD_BANK0_VGC_P8MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_VGC_P8MODE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_P8MODE_ENABLE]

//>> SET_[MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE]

//>> SET_[MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE]

//>> SET_[MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.setBit<MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE]

//>> CLEAR_[MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.clearBit<MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE]

//>> GET_[MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.extractToRight<MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE]

//>> GET_[MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE]
static inline bool GET_MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.getBit<MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE]

//>> SET_[MCD_BANK0_VGC_EXT_ADDR_FAC_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_EXT_ADDR_FAC_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_EXT_ADDR_FAC_MASK,
           MCD_BANK0_VGC_EXT_ADDR_FAC_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_VGC_EXT_ADDR_FAC_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_EXT_ADDR_FAC_MASK]

//>> SET_[MCD_BANK0_VGC_EXT_ADDR_FAC_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_EXT_ADDR_FAC_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_EXT_ADDR_FAC_MASK,
           MCD_BANK0_VGC_EXT_ADDR_FAC_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_VGC_EXT_ADDR_FAC_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_EXT_ADDR_FAC_MASK]

//>> GET_[MCD_BANK0_VGC_EXT_ADDR_FAC_MASK]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_VGC_EXT_ADDR_FAC_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.extractToRight<MCD_BANK0_VGC_EXT_ADDR_FAC_MASK,
           MCD_BANK0_VGC_EXT_ADDR_FAC_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_VGC_EXT_ADDR_FAC_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_EXT_ADDR_FAC_MASK]

//>> SET_[MCD_BANK0_VGC_EXT_ADDR_VEC_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_EXT_ADDR_VEC_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_EXT_ADDR_VEC_ENABLE,
           MCD_BANK0_VGC_EXT_ADDR_VEC_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_VGC_EXT_ADDR_VEC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_EXT_ADDR_VEC_ENABLE]

//>> SET_[MCD_BANK0_VGC_EXT_ADDR_VEC_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_EXT_ADDR_VEC_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_EXT_ADDR_VEC_ENABLE,
           MCD_BANK0_VGC_EXT_ADDR_VEC_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_VGC_EXT_ADDR_VEC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_EXT_ADDR_VEC_ENABLE]

//>> GET_[MCD_BANK0_VGC_EXT_ADDR_VEC_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_VGC_EXT_ADDR_VEC_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.extractToRight<MCD_BANK0_VGC_EXT_ADDR_VEC_ENABLE,
           MCD_BANK0_VGC_EXT_ADDR_VEC_ENABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_VGC_EXT_ADDR_VEC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_EXT_ADDR_VEC_ENABLE]

//>> SET_[MCD_BANK0_VGC_CS_HW400693_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_CS_HW400693_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_CS_HW400693_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_VGC_CS_HW400693_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_CS_HW400693_DISABLE]

//>> SET_[MCD_BANK0_VGC_CS_HW400693_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_CS_HW400693_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_CS_HW400693_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_VGC_CS_HW400693_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_CS_HW400693_DISABLE]

//>> SET_[MCD_BANK0_VGC_CS_HW400693_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_CS_HW400693_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.setBit<MCD_BANK0_VGC_CS_HW400693_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_VGC_CS_HW400693_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_CS_HW400693_DISABLE]

//>> CLEAR_[MCD_BANK0_VGC_CS_HW400693_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_VGC_CS_HW400693_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.clearBit<MCD_BANK0_VGC_CS_HW400693_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_VGC_CS_HW400693_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_VGC_CS_HW400693_DISABLE]

//>> GET_[MCD_BANK0_VGC_CS_HW400693_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_VGC_CS_HW400693_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.extractToRight<MCD_BANK0_VGC_CS_HW400693_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_VGC_CS_HW400693_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_CS_HW400693_DISABLE]

//>> GET_[MCD_BANK0_VGC_CS_HW400693_DISABLE]
static inline bool GET_MCD_BANK0_VGC_CS_HW400693_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.getBit<MCD_BANK0_VGC_CS_HW400693_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_VGC_CS_HW400693_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_CS_HW400693_DISABLE]

//>> SET_[MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG]

//>> SET_[MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG]

//>> SET_[MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.setBit<MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG]

//>> CLEAR_[MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.clearBit<MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG]

//>> GET_[MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.extractToRight<MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG]

//>> GET_[MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG]
static inline bool GET_MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.getBit<MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG]

//>> SET_[MCD_BANK0_VGC_CS_HW403560_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_CS_HW403560_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_CS_HW403560_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_VGC_CS_HW403560_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_CS_HW403560_DISABLE]

//>> SET_[MCD_BANK0_VGC_CS_HW403560_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_CS_HW403560_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_CS_HW403560_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_VGC_CS_HW403560_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_CS_HW403560_DISABLE]

//>> SET_[MCD_BANK0_VGC_CS_HW403560_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_CS_HW403560_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.setBit<MCD_BANK0_VGC_CS_HW403560_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_VGC_CS_HW403560_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_CS_HW403560_DISABLE]

//>> CLEAR_[MCD_BANK0_VGC_CS_HW403560_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_VGC_CS_HW403560_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.clearBit<MCD_BANK0_VGC_CS_HW403560_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_VGC_CS_HW403560_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_VGC_CS_HW403560_DISABLE]

//>> GET_[MCD_BANK0_VGC_CS_HW403560_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_VGC_CS_HW403560_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.extractToRight<MCD_BANK0_VGC_CS_HW403560_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_VGC_CS_HW403560_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_CS_HW403560_DISABLE]

//>> GET_[MCD_BANK0_VGC_CS_HW403560_DISABLE]
static inline bool GET_MCD_BANK0_VGC_CS_HW403560_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.getBit<MCD_BANK0_VGC_CS_HW403560_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_VGC_CS_HW403560_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_CS_HW403560_DISABLE]

//>> SET_[MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE]

//>> SET_[MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE]

//>> SET_[MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.setBit<MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE]

//>> CLEAR_[MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.clearBit<MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE]

//>> GET_[MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.extractToRight<MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE]

//>> GET_[MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE]
static inline bool GET_MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.getBit<MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE]

//>> SET_[MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE]

//>> SET_[MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE]

//>> SET_[MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.setBit<MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE]

//>> CLEAR_[MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.clearBit<MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE]

//>> GET_[MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.extractToRight<MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE]

//>> GET_[MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE]
static inline bool GET_MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.getBit<MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE]

//>> SET_[MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE]

//>> SET_[MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE]

//>> SET_[MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.setBit<MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE]

//>> CLEAR_[MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.clearBit<MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE]

//>> GET_[MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.extractToRight<MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE]

//>> GET_[MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE]
static inline bool GET_MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.getBit<MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE]

//>> SET_[MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE]

//>> SET_[MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE]

//>> SET_[MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.setBit<MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE]

//>> CLEAR_[MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.clearBit<MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE]

//>> GET_[MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.extractToRight<MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE]

//>> GET_[MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE]
static inline bool GET_MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.getBit<MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE]

//>> SET_[MCD_BANK0_VGC_1MB_GRANULE_MODE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_1MB_GRANULE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_1MB_GRANULE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_VGC_1MB_GRANULE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_1MB_GRANULE_MODE]

//>> SET_[MCD_BANK0_VGC_1MB_GRANULE_MODE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_1MB_GRANULE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_1MB_GRANULE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_VGC_1MB_GRANULE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_1MB_GRANULE_MODE]

//>> SET_[MCD_BANK0_VGC_1MB_GRANULE_MODE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_1MB_GRANULE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.setBit<MCD_BANK0_VGC_1MB_GRANULE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_VGC_1MB_GRANULE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_1MB_GRANULE_MODE]

//>> CLEAR_[MCD_BANK0_VGC_1MB_GRANULE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_VGC_1MB_GRANULE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.clearBit<MCD_BANK0_VGC_1MB_GRANULE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_VGC_1MB_GRANULE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_VGC_1MB_GRANULE_MODE]

//>> GET_[MCD_BANK0_VGC_1MB_GRANULE_MODE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_VGC_1MB_GRANULE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.extractToRight<MCD_BANK0_VGC_1MB_GRANULE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_VGC_1MB_GRANULE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_1MB_GRANULE_MODE]

//>> GET_[MCD_BANK0_VGC_1MB_GRANULE_MODE]
static inline bool GET_MCD_BANK0_VGC_1MB_GRANULE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.getBit<MCD_BANK0_VGC_1MB_GRANULE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_VGC_1MB_GRANULE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_1MB_GRANULE_MODE]

//>> SET_[MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE]

//>> SET_[MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE]

//>> SET_[MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.setBit<MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE]

//>> CLEAR_[MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.clearBit<MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE]

//>> GET_[MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.extractToRight<MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE]

//>> GET_[MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE]
static inline bool GET_MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.getBit<MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE]

//>> SET_[MCD_BANK0_VGC_SPARE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_SPARE,
           MCD_BANK0_VGC_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_VGC_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_SPARE]

//>> SET_[MCD_BANK0_VGC_SPARE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_VGC_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return o_data.insertFromRight<MCD_BANK0_VGC_SPARE,
           MCD_BANK0_VGC_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_VGC_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_VGC_SPARE]

//>> GET_[MCD_BANK0_VGC_SPARE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_VGC_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_VGC));
#endif
    return i_data.extractToRight<MCD_BANK0_VGC_SPARE,
           MCD_BANK0_VGC_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_VGC_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_VGC_SPARE]

//>> PREP_[NX_DMA_SU_STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_DMA_SU_STATUS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_DMA_SU_STATUS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NX_DMA_SU_STATUS]

//>> GET_[NX_DMA_SU_STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_DMA_SU_STATUS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_DMA_SU_STATUS;
#endif
    return fapi2::getScom(i_target, NX_DMA_SU_STATUS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NX_DMA_SU_STATUS]

//>> PUT_[NX_DMA_SU_STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_DMA_SU_STATUS(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return fapi2::putScom(i_target, NX_DMA_SU_STATUS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NX_DMA_SU_STATUS]


//>> SET_[NX_DMA_SU_STATUS_HMI_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_STATUS_HMI_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.insertFromRight<NX_DMA_SU_STATUS_HMI_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_DMA_SU_STATUS_HMI_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_STATUS_HMI_ACTIVE]

//>> SET_[NX_DMA_SU_STATUS_HMI_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_STATUS_HMI_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.insertFromRight<NX_DMA_SU_STATUS_HMI_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_DMA_SU_STATUS_HMI_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_STATUS_HMI_ACTIVE]

//>> SET_[NX_DMA_SU_STATUS_HMI_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_STATUS_HMI_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.setBit<NX_DMA_SU_STATUS_HMI_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_DMA_SU_STATUS_HMI_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_STATUS_HMI_ACTIVE]

//>> CLEAR_[NX_DMA_SU_STATUS_HMI_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_DMA_SU_STATUS_HMI_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.clearBit<NX_DMA_SU_STATUS_HMI_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_DMA_SU_STATUS_HMI_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_DMA_SU_STATUS_HMI_ACTIVE]

//>> GET_[NX_DMA_SU_STATUS_HMI_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_STATUS_HMI_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return i_data.extractToRight<NX_DMA_SU_STATUS_HMI_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_DMA_SU_STATUS_HMI_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_DMA_SU_STATUS_HMI_ACTIVE]

//>> GET_[NX_DMA_SU_STATUS_HMI_ACTIVE]
static inline bool GET_NX_DMA_SU_STATUS_HMI_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return i_data.getBit<NX_DMA_SU_STATUS_HMI_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_DMA_SU_STATUS_HMI_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_DMA_SU_STATUS_HMI_ACTIVE]

//>> SET_[NX_DMA_SU_STATUS_PBI_IDLE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_STATUS_PBI_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.insertFromRight<NX_DMA_SU_STATUS_PBI_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_DMA_SU_STATUS_PBI_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_STATUS_PBI_IDLE]

//>> SET_[NX_DMA_SU_STATUS_PBI_IDLE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_STATUS_PBI_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.insertFromRight<NX_DMA_SU_STATUS_PBI_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_DMA_SU_STATUS_PBI_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_STATUS_PBI_IDLE]

//>> SET_[NX_DMA_SU_STATUS_PBI_IDLE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_STATUS_PBI_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.setBit<NX_DMA_SU_STATUS_PBI_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_DMA_SU_STATUS_PBI_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_STATUS_PBI_IDLE]

//>> CLEAR_[NX_DMA_SU_STATUS_PBI_IDLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_DMA_SU_STATUS_PBI_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.clearBit<NX_DMA_SU_STATUS_PBI_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_DMA_SU_STATUS_PBI_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_DMA_SU_STATUS_PBI_IDLE]

//>> GET_[NX_DMA_SU_STATUS_PBI_IDLE]
static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_STATUS_PBI_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return i_data.extractToRight<NX_DMA_SU_STATUS_PBI_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_DMA_SU_STATUS_PBI_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_DMA_SU_STATUS_PBI_IDLE]

//>> GET_[NX_DMA_SU_STATUS_PBI_IDLE]
static inline bool GET_NX_DMA_SU_STATUS_PBI_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return i_data.getBit<NX_DMA_SU_STATUS_PBI_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_DMA_SU_STATUS_PBI_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_DMA_SU_STATUS_PBI_IDLE]

//>> SET_[NX_DMA_SU_STATUS_DMA_CH0_IDLE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_STATUS_DMA_CH0_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.insertFromRight<NX_DMA_SU_STATUS_DMA_CH0_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH0_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_STATUS_DMA_CH0_IDLE]

//>> SET_[NX_DMA_SU_STATUS_DMA_CH0_IDLE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_STATUS_DMA_CH0_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.insertFromRight<NX_DMA_SU_STATUS_DMA_CH0_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH0_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_STATUS_DMA_CH0_IDLE]

//>> SET_[NX_DMA_SU_STATUS_DMA_CH0_IDLE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_STATUS_DMA_CH0_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.setBit<NX_DMA_SU_STATUS_DMA_CH0_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH0_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_STATUS_DMA_CH0_IDLE]

//>> CLEAR_[NX_DMA_SU_STATUS_DMA_CH0_IDLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_DMA_SU_STATUS_DMA_CH0_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.clearBit<NX_DMA_SU_STATUS_DMA_CH0_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH0_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_DMA_SU_STATUS_DMA_CH0_IDLE]

//>> GET_[NX_DMA_SU_STATUS_DMA_CH0_IDLE]
static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_STATUS_DMA_CH0_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return i_data.extractToRight<NX_DMA_SU_STATUS_DMA_CH0_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH0_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_DMA_SU_STATUS_DMA_CH0_IDLE]

//>> GET_[NX_DMA_SU_STATUS_DMA_CH0_IDLE]
static inline bool GET_NX_DMA_SU_STATUS_DMA_CH0_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return i_data.getBit<NX_DMA_SU_STATUS_DMA_CH0_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH0_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_DMA_SU_STATUS_DMA_CH0_IDLE]

//>> SET_[NX_DMA_SU_STATUS_DMA_CH1_IDLE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_STATUS_DMA_CH1_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.insertFromRight<NX_DMA_SU_STATUS_DMA_CH1_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH1_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_STATUS_DMA_CH1_IDLE]

//>> SET_[NX_DMA_SU_STATUS_DMA_CH1_IDLE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_STATUS_DMA_CH1_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.insertFromRight<NX_DMA_SU_STATUS_DMA_CH1_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH1_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_STATUS_DMA_CH1_IDLE]

//>> SET_[NX_DMA_SU_STATUS_DMA_CH1_IDLE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_STATUS_DMA_CH1_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.setBit<NX_DMA_SU_STATUS_DMA_CH1_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH1_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_STATUS_DMA_CH1_IDLE]

//>> CLEAR_[NX_DMA_SU_STATUS_DMA_CH1_IDLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_DMA_SU_STATUS_DMA_CH1_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.clearBit<NX_DMA_SU_STATUS_DMA_CH1_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH1_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_DMA_SU_STATUS_DMA_CH1_IDLE]

//>> GET_[NX_DMA_SU_STATUS_DMA_CH1_IDLE]
static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_STATUS_DMA_CH1_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return i_data.extractToRight<NX_DMA_SU_STATUS_DMA_CH1_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH1_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_DMA_SU_STATUS_DMA_CH1_IDLE]

//>> GET_[NX_DMA_SU_STATUS_DMA_CH1_IDLE]
static inline bool GET_NX_DMA_SU_STATUS_DMA_CH1_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return i_data.getBit<NX_DMA_SU_STATUS_DMA_CH1_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH1_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_DMA_SU_STATUS_DMA_CH1_IDLE]

//>> SET_[NX_DMA_SU_STATUS_DMA_CH2_IDLE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_STATUS_DMA_CH2_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.insertFromRight<NX_DMA_SU_STATUS_DMA_CH2_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH2_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_STATUS_DMA_CH2_IDLE]

//>> SET_[NX_DMA_SU_STATUS_DMA_CH2_IDLE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_STATUS_DMA_CH2_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.insertFromRight<NX_DMA_SU_STATUS_DMA_CH2_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH2_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_STATUS_DMA_CH2_IDLE]

//>> SET_[NX_DMA_SU_STATUS_DMA_CH2_IDLE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_STATUS_DMA_CH2_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.setBit<NX_DMA_SU_STATUS_DMA_CH2_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH2_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_STATUS_DMA_CH2_IDLE]

//>> CLEAR_[NX_DMA_SU_STATUS_DMA_CH2_IDLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_DMA_SU_STATUS_DMA_CH2_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.clearBit<NX_DMA_SU_STATUS_DMA_CH2_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH2_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_DMA_SU_STATUS_DMA_CH2_IDLE]

//>> GET_[NX_DMA_SU_STATUS_DMA_CH2_IDLE]
static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_STATUS_DMA_CH2_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return i_data.extractToRight<NX_DMA_SU_STATUS_DMA_CH2_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH2_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_DMA_SU_STATUS_DMA_CH2_IDLE]

//>> GET_[NX_DMA_SU_STATUS_DMA_CH2_IDLE]
static inline bool GET_NX_DMA_SU_STATUS_DMA_CH2_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return i_data.getBit<NX_DMA_SU_STATUS_DMA_CH2_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH2_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_DMA_SU_STATUS_DMA_CH2_IDLE]

//>> SET_[NX_DMA_SU_STATUS_DMA_CH3_IDLE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_STATUS_DMA_CH3_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.insertFromRight<NX_DMA_SU_STATUS_DMA_CH3_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH3_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_STATUS_DMA_CH3_IDLE]

//>> SET_[NX_DMA_SU_STATUS_DMA_CH3_IDLE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_STATUS_DMA_CH3_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.insertFromRight<NX_DMA_SU_STATUS_DMA_CH3_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH3_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_STATUS_DMA_CH3_IDLE]

//>> SET_[NX_DMA_SU_STATUS_DMA_CH3_IDLE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_STATUS_DMA_CH3_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.setBit<NX_DMA_SU_STATUS_DMA_CH3_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH3_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_STATUS_DMA_CH3_IDLE]

//>> CLEAR_[NX_DMA_SU_STATUS_DMA_CH3_IDLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_DMA_SU_STATUS_DMA_CH3_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.clearBit<NX_DMA_SU_STATUS_DMA_CH3_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH3_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_DMA_SU_STATUS_DMA_CH3_IDLE]

//>> GET_[NX_DMA_SU_STATUS_DMA_CH3_IDLE]
static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_STATUS_DMA_CH3_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return i_data.extractToRight<NX_DMA_SU_STATUS_DMA_CH3_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH3_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_DMA_SU_STATUS_DMA_CH3_IDLE]

//>> GET_[NX_DMA_SU_STATUS_DMA_CH3_IDLE]
static inline bool GET_NX_DMA_SU_STATUS_DMA_CH3_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return i_data.getBit<NX_DMA_SU_STATUS_DMA_CH3_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH3_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_DMA_SU_STATUS_DMA_CH3_IDLE]

//>> SET_[NX_DMA_SU_STATUS_DMA_CH4_IDLE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_STATUS_DMA_CH4_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.insertFromRight<NX_DMA_SU_STATUS_DMA_CH4_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH4_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_STATUS_DMA_CH4_IDLE]

//>> SET_[NX_DMA_SU_STATUS_DMA_CH4_IDLE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_STATUS_DMA_CH4_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.insertFromRight<NX_DMA_SU_STATUS_DMA_CH4_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH4_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_STATUS_DMA_CH4_IDLE]

//>> SET_[NX_DMA_SU_STATUS_DMA_CH4_IDLE]
static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SU_STATUS_DMA_CH4_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.setBit<NX_DMA_SU_STATUS_DMA_CH4_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH4_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_DMA_SU_STATUS_DMA_CH4_IDLE]

//>> CLEAR_[NX_DMA_SU_STATUS_DMA_CH4_IDLE]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_DMA_SU_STATUS_DMA_CH4_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return o_data.clearBit<NX_DMA_SU_STATUS_DMA_CH4_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH4_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_DMA_SU_STATUS_DMA_CH4_IDLE]

//>> GET_[NX_DMA_SU_STATUS_DMA_CH4_IDLE]
static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SU_STATUS_DMA_CH4_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return i_data.extractToRight<NX_DMA_SU_STATUS_DMA_CH4_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH4_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_DMA_SU_STATUS_DMA_CH4_IDLE]

//>> GET_[NX_DMA_SU_STATUS_DMA_CH4_IDLE]
static inline bool GET_NX_DMA_SU_STATUS_DMA_CH4_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SU_STATUS));
#endif
    return i_data.getBit<NX_DMA_SU_STATUS_DMA_CH4_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_DMA_SU_STATUS_DMA_CH4_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_DMA_SU_STATUS_DMA_CH4_IDLE]

//>> PREP_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE]

//>> GET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE]

//>> PUT_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE]


//>> SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_0_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_0_EQ0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_0_EQ0,
           PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_0_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_0_EQ0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_0_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_0_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_0_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_0_EQ0,
           PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_0_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_0_EQ0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_0_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_0_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_0_EQ0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_0_EQ0,
           PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_0_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_0_EQ0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_0_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_1_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_1_EQ0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_1_EQ0,
           PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_1_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_1_EQ0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_1_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_1_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_1_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_1_EQ0,
           PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_1_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_1_EQ0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_1_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_1_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_1_EQ0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_1_EQ0,
           PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_1_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_1_EQ0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_1_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_2_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_2_EQ0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_2_EQ0,
           PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_2_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_2_EQ0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_2_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_2_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_2_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_2_EQ0,
           PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_2_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_2_EQ0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_2_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_2_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_2_EQ0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_2_EQ0,
           PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_2_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_2_EQ0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_2_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_3_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_3_EQ0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_3_EQ0,
           PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_3_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_3_EQ0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_3_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_3_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_3_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_3_EQ0,
           PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_3_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_3_EQ0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_3_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_3_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_3_EQ0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_3_EQ0,
           PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_3_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_3_EQ0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_3_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_4_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_4_EQ0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_4_EQ0,
           PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_4_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_4_EQ0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_4_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_4_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_4_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_4_EQ0,
           PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_4_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_4_EQ0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_4_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_4_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_4_EQ0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_4_EQ0,
           PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_4_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_4_EQ0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_4_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_5_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_5_EQ0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_5_EQ0,
           PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_5_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_5_EQ0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_5_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_5_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_5_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_5_EQ0,
           PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_5_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_5_EQ0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_5_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_5_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_5_EQ0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_5_EQ0,
           PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_5_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_5_EQ0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_5_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_6_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_6_EQ0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_6_EQ0,
           PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_6_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_6_EQ0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_6_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_6_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_6_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_6_EQ0,
           PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_6_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_6_EQ0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_6_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_6_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_6_EQ0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_6_EQ0,
           PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_6_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_6_EQ0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_6_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_7_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_7_EQ0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_7_EQ0,
           PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_7_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_7_EQ0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_7_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_7_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_7_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_7_EQ0,
           PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_7_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_7_EQ0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_7_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_7_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_7_EQ0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_7_EQ0,
           PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_7_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_7_EQ0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_SP_CMD_RATE_7_EQ0]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
