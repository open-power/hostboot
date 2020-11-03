/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00070.H $         */
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

#ifndef __PROC_REG00070_H_
#define __PROC_REG00070_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[INT_VC_ESBC_FLUSH_CTRL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ESBC_FLUSH_CTRL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ESBC_FLUSH_CTRL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[INT_VC_ESBC_FLUSH_CTRL]

//>> GET_[INT_VC_ESBC_FLUSH_CTRL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ESBC_FLUSH_CTRL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ESBC_FLUSH_CTRL;
#endif
    return fapi2::getScom(i_target, INT_VC_ESBC_FLUSH_CTRL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[INT_VC_ESBC_FLUSH_CTRL]

//>> PUT_[INT_VC_ESBC_FLUSH_CTRL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ESBC_FLUSH_CTRL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_FLUSH_CTRL));
#endif
    return fapi2::putScom(i_target, INT_VC_ESBC_FLUSH_CTRL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[INT_VC_ESBC_FLUSH_CTRL]


//>> SET_[INT_VC_ESBC_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_FLUSH_CTRL_POLL_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_VC_ESBC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ESBC_FLUSH_CTRL_POLL_VALID]

//>> SET_[INT_VC_ESBC_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_FLUSH_CTRL_POLL_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_FLUSH_CTRL_POLL_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_VC_ESBC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ESBC_FLUSH_CTRL_POLL_VALID]

//>> SET_[INT_VC_ESBC_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_FLUSH_CTRL));
#endif
    return o_data.setBit<INT_VC_ESBC_FLUSH_CTRL_POLL_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_VC_ESBC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ESBC_FLUSH_CTRL_POLL_VALID]

//>> CLEAR_[INT_VC_ESBC_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_ESBC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_FLUSH_CTRL));
#endif
    return o_data.clearBit<INT_VC_ESBC_FLUSH_CTRL_POLL_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_VC_ESBC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_VC_ESBC_FLUSH_CTRL_POLL_VALID]

//>> GET_[INT_VC_ESBC_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_VC_ESBC_FLUSH_CTRL_POLL_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_VC_ESBC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ESBC_FLUSH_CTRL_POLL_VALID]

//>> GET_[INT_VC_ESBC_FLUSH_CTRL_POLL_VALID]
static inline bool GET_INT_VC_ESBC_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_FLUSH_CTRL));
#endif
    return i_data.getBit<INT_VC_ESBC_FLUSH_CTRL_POLL_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_VC_ESBC_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ESBC_FLUSH_CTRL_POLL_VALID]

//>> SET_[INT_VC_ESBC_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_FLUSH_CTRL_RESERVED_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_VC_ESBC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ESBC_FLUSH_CTRL_RESERVED_1]

//>> SET_[INT_VC_ESBC_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_FLUSH_CTRL_RESERVED_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_FLUSH_CTRL_RESERVED_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_VC_ESBC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ESBC_FLUSH_CTRL_RESERVED_1]

//>> SET_[INT_VC_ESBC_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_FLUSH_CTRL));
#endif
    return o_data.setBit<INT_VC_ESBC_FLUSH_CTRL_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_VC_ESBC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ESBC_FLUSH_CTRL_RESERVED_1]

//>> CLEAR_[INT_VC_ESBC_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_ESBC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_FLUSH_CTRL));
#endif
    return o_data.clearBit<INT_VC_ESBC_FLUSH_CTRL_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_VC_ESBC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_VC_ESBC_FLUSH_CTRL_RESERVED_1]

//>> GET_[INT_VC_ESBC_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_VC_ESBC_FLUSH_CTRL_RESERVED_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_VC_ESBC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ESBC_FLUSH_CTRL_RESERVED_1]

//>> GET_[INT_VC_ESBC_FLUSH_CTRL_RESERVED_1]
static inline bool GET_INT_VC_ESBC_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_FLUSH_CTRL));
#endif
    return i_data.getBit<INT_VC_ESBC_FLUSH_CTRL_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_VC_ESBC_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ESBC_FLUSH_CTRL_RESERVED_1]

//>> SET_[INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> SET_[INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> SET_[INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_FLUSH_CTRL));
#endif
    return o_data.setBit<INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> CLEAR_[INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_FLUSH_CTRL));
#endif
    return o_data.clearBit<INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> GET_[INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> GET_[INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline bool GET_INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_FLUSH_CTRL));
#endif
    return i_data.getBit<INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ESBC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> SET_[INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7,
           INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7]

//>> SET_[INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7]
static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7,
           INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7]

//>> GET_[INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7]
static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESBC_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7,
           INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_VC_ESBC_FLUSH_CTRL_RESERVED_3_7]

//>> PREP_[MCD_BANK0_REC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_BANK0_REC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_BANK0_REC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MCD_BANK0_REC]

//>> GET_[MCD_BANK0_REC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_BANK0_REC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_BANK0_REC;
#endif
    return fapi2::getScom(i_target, MCD_BANK0_REC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MCD_BANK0_REC]

//>> PUT_[MCD_BANK0_REC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_BANK0_REC(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return fapi2::putScom(i_target, MCD_BANK0_REC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MCD_BANK0_REC]


//>> SET_[MCD_BANK0_REC_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_REC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_ENABLE]

//>> SET_[MCD_BANK0_REC_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_REC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_ENABLE]

//>> SET_[MCD_BANK0_REC_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.setBit<MCD_BANK0_REC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_REC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_ENABLE]

//>> CLEAR_[MCD_BANK0_REC_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_REC_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.clearBit<MCD_BANK0_REC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_REC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_REC_ENABLE]

//>> GET_[MCD_BANK0_REC_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_REC_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return i_data.extractToRight<MCD_BANK0_REC_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_REC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_REC_ENABLE]

//>> GET_[MCD_BANK0_REC_ENABLE]
static inline bool GET_MCD_BANK0_REC_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return i_data.getBit<MCD_BANK0_REC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_REC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_REC_ENABLE]

//>> SET_[MCD_BANK0_REC_DONE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_REC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_DONE]

//>> SET_[MCD_BANK0_REC_DONE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_REC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_DONE]

//>> SET_[MCD_BANK0_REC_DONE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.setBit<MCD_BANK0_REC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_REC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_DONE]

//>> CLEAR_[MCD_BANK0_REC_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_REC_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.clearBit<MCD_BANK0_REC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_REC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_REC_DONE]

//>> GET_[MCD_BANK0_REC_DONE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_REC_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return i_data.extractToRight<MCD_BANK0_REC_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_REC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_REC_DONE]

//>> GET_[MCD_BANK0_REC_DONE]
static inline bool GET_MCD_BANK0_REC_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return i_data.getBit<MCD_BANK0_REC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_REC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_REC_DONE]

//>> SET_[MCD_BANK0_REC_CONTINUOUS]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_CONTINUOUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_CONTINUOUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_REC_CONTINUOUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_CONTINUOUS]

//>> SET_[MCD_BANK0_REC_CONTINUOUS]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_CONTINUOUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_CONTINUOUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_REC_CONTINUOUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_CONTINUOUS]

//>> SET_[MCD_BANK0_REC_CONTINUOUS]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_CONTINUOUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.setBit<MCD_BANK0_REC_CONTINUOUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_REC_CONTINUOUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_CONTINUOUS]

//>> CLEAR_[MCD_BANK0_REC_CONTINUOUS]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_REC_CONTINUOUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.clearBit<MCD_BANK0_REC_CONTINUOUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_REC_CONTINUOUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_REC_CONTINUOUS]

//>> GET_[MCD_BANK0_REC_CONTINUOUS]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_REC_CONTINUOUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return i_data.extractToRight<MCD_BANK0_REC_CONTINUOUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_REC_CONTINUOUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_REC_CONTINUOUS]

//>> GET_[MCD_BANK0_REC_CONTINUOUS]
static inline bool GET_MCD_BANK0_REC_CONTINUOUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return i_data.getBit<MCD_BANK0_REC_CONTINUOUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_REC_CONTINUOUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_REC_CONTINUOUS]

//>> SET_[MCD_BANK0_REC_FILTER_ADDR_DIS]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_FILTER_ADDR_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_FILTER_ADDR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_REC_FILTER_ADDR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_FILTER_ADDR_DIS]

//>> SET_[MCD_BANK0_REC_FILTER_ADDR_DIS]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_FILTER_ADDR_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_FILTER_ADDR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_REC_FILTER_ADDR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_FILTER_ADDR_DIS]

//>> SET_[MCD_BANK0_REC_FILTER_ADDR_DIS]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_FILTER_ADDR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.setBit<MCD_BANK0_REC_FILTER_ADDR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_REC_FILTER_ADDR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_FILTER_ADDR_DIS]

//>> CLEAR_[MCD_BANK0_REC_FILTER_ADDR_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_REC_FILTER_ADDR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.clearBit<MCD_BANK0_REC_FILTER_ADDR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_REC_FILTER_ADDR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_REC_FILTER_ADDR_DIS]

//>> GET_[MCD_BANK0_REC_FILTER_ADDR_DIS]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_REC_FILTER_ADDR_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return i_data.extractToRight<MCD_BANK0_REC_FILTER_ADDR_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_REC_FILTER_ADDR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_REC_FILTER_ADDR_DIS]

//>> GET_[MCD_BANK0_REC_FILTER_ADDR_DIS]
static inline bool GET_MCD_BANK0_REC_FILTER_ADDR_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return i_data.getBit<MCD_BANK0_REC_FILTER_ADDR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_REC_FILTER_ADDR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_REC_FILTER_ADDR_DIS]

//>> SET_[MCD_BANK0_REC_RETRY_COUNT_EXCEED]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_RETRY_COUNT_EXCEED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_RETRY_COUNT_EXCEED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_REC_RETRY_COUNT_EXCEED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_RETRY_COUNT_EXCEED]

//>> SET_[MCD_BANK0_REC_RETRY_COUNT_EXCEED]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_RETRY_COUNT_EXCEED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_RETRY_COUNT_EXCEED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_REC_RETRY_COUNT_EXCEED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_RETRY_COUNT_EXCEED]

//>> SET_[MCD_BANK0_REC_RETRY_COUNT_EXCEED]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_RETRY_COUNT_EXCEED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.setBit<MCD_BANK0_REC_RETRY_COUNT_EXCEED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_REC_RETRY_COUNT_EXCEED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_RETRY_COUNT_EXCEED]

//>> CLEAR_[MCD_BANK0_REC_RETRY_COUNT_EXCEED]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_REC_RETRY_COUNT_EXCEED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.clearBit<MCD_BANK0_REC_RETRY_COUNT_EXCEED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_REC_RETRY_COUNT_EXCEED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_REC_RETRY_COUNT_EXCEED]

//>> GET_[MCD_BANK0_REC_RETRY_COUNT_EXCEED]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_REC_RETRY_COUNT_EXCEED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return i_data.extractToRight<MCD_BANK0_REC_RETRY_COUNT_EXCEED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_REC_RETRY_COUNT_EXCEED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_REC_RETRY_COUNT_EXCEED]

//>> GET_[MCD_BANK0_REC_RETRY_COUNT_EXCEED]
static inline bool GET_MCD_BANK0_REC_RETRY_COUNT_EXCEED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return i_data.getBit<MCD_BANK0_REC_RETRY_COUNT_EXCEED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_REC_RETRY_COUNT_EXCEED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_REC_RETRY_COUNT_EXCEED]

//>> SET_[MCD_BANK0_REC_STATUS]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_REC_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_STATUS]

//>> SET_[MCD_BANK0_REC_STATUS]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_REC_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_STATUS]

//>> SET_[MCD_BANK0_REC_STATUS]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.setBit<MCD_BANK0_REC_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_REC_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_STATUS]

//>> CLEAR_[MCD_BANK0_REC_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_REC_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.clearBit<MCD_BANK0_REC_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_REC_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_REC_STATUS]

//>> GET_[MCD_BANK0_REC_STATUS]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_REC_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return i_data.extractToRight<MCD_BANK0_REC_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_REC_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_REC_STATUS]

//>> GET_[MCD_BANK0_REC_STATUS]
static inline bool GET_MCD_BANK0_REC_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return i_data.getBit<MCD_BANK0_REC_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_REC_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_REC_STATUS]

//>> SET_[MCD_BANK0_REC_PACE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_PACE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_PACE,
           MCD_BANK0_REC_PACE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_REC_PACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_PACE]

//>> SET_[MCD_BANK0_REC_PACE]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_PACE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_PACE,
           MCD_BANK0_REC_PACE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_REC_PACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_PACE]

//>> GET_[MCD_BANK0_REC_PACE]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_REC_PACE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return i_data.extractToRight<MCD_BANK0_REC_PACE,
           MCD_BANK0_REC_PACE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_REC_PACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_REC_PACE]

//>> SET_[MCD_BANK0_REC_ADDR_ERROR]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_ADDR_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_ADDR_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_REC_ADDR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_ADDR_ERROR]

//>> SET_[MCD_BANK0_REC_ADDR_ERROR]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_ADDR_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_ADDR_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_REC_ADDR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_ADDR_ERROR]

//>> SET_[MCD_BANK0_REC_ADDR_ERROR]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_ADDR_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.setBit<MCD_BANK0_REC_ADDR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_BANK0_REC_ADDR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_ADDR_ERROR]

//>> CLEAR_[MCD_BANK0_REC_ADDR_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_REC_ADDR_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.clearBit<MCD_BANK0_REC_ADDR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_BANK0_REC_ADDR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_BANK0_REC_ADDR_ERROR]

//>> GET_[MCD_BANK0_REC_ADDR_ERROR]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_REC_ADDR_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return i_data.extractToRight<MCD_BANK0_REC_ADDR_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_REC_ADDR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_REC_ADDR_ERROR]

//>> GET_[MCD_BANK0_REC_ADDR_ERROR]
static inline bool GET_MCD_BANK0_REC_ADDR_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return i_data.getBit<MCD_BANK0_REC_ADDR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_BANK0_REC_ADDR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_REC_ADDR_ERROR]

//>> SET_[MCD_BANK0_REC_ADDR]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_ADDR,
           MCD_BANK0_REC_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_REC_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_ADDR]

//>> SET_[MCD_BANK0_REC_ADDR]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_ADDR,
           MCD_BANK0_REC_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_REC_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_ADDR]

//>> GET_[MCD_BANK0_REC_ADDR]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_REC_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return i_data.extractToRight<MCD_BANK0_REC_ADDR,
           MCD_BANK0_REC_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_REC_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_REC_ADDR]

//>> SET_[MCD_BANK0_REC_RTY_COUNT]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_RTY_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_RTY_COUNT,
           MCD_BANK0_REC_RTY_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_REC_RTY_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_RTY_COUNT]

//>> SET_[MCD_BANK0_REC_RTY_COUNT]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_RTY_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_RTY_COUNT,
           MCD_BANK0_REC_RTY_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_REC_RTY_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_RTY_COUNT]

//>> GET_[MCD_BANK0_REC_RTY_COUNT]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_REC_RTY_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return i_data.extractToRight<MCD_BANK0_REC_RTY_COUNT,
           MCD_BANK0_REC_RTY_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_REC_RTY_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_REC_RTY_COUNT]

//>> SET_[MCD_BANK0_REC_VG_COUNT]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_VG_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_VG_COUNT,
           MCD_BANK0_REC_VG_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_BANK0_REC_VG_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_VG_COUNT]

//>> SET_[MCD_BANK0_REC_VG_COUNT]
static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_REC_VG_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return o_data.insertFromRight<MCD_BANK0_REC_VG_COUNT,
           MCD_BANK0_REC_VG_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_BANK0_REC_VG_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_BANK0_REC_VG_COUNT]

//>> GET_[MCD_BANK0_REC_VG_COUNT]
static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_REC_VG_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_REC));
#endif
    return i_data.extractToRight<MCD_BANK0_REC_VG_COUNT,
           MCD_BANK0_REC_VG_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_BANK0_REC_VG_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_BANK0_REC_VG_COUNT]

//>> PREP_[PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT]

//>> PUT_[PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT]


//>> SET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT,
           PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT,
           PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT,
           PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT]

//>> PREP_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT]

//>> PUT_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT]


//>> SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT,
           PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT,
           PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT,
           PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT]

//>> PREP_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR]

//>> PUT_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR]


//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_VALID_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_16_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_17_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_18_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_19_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_20_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_21_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_22_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_23_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_24_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_25_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_26_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_27_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_28_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_29_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_30_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR_31_AX_NUM_CURR_EQ0]

//>> PREP_[PB_COM_SCOM_EQ0_STATION_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_EQ0_STATION_MODE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_MODE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_EQ0_STATION_MODE]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_EQ0_STATION_MODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_MODE;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_EQ0_STATION_MODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE]

//>> PUT_[PB_COM_SCOM_EQ0_STATION_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_EQ0_STATION_MODE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_EQ0_STATION_MODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_EQ0_STATION_MODE]


//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_PBIXXX_INIT]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_DBG_MAX_HANG_STAGE_REACHED]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_DBG_MAX_HANG_STAGE_REACHED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_DBG_MAX_HANG_STAGE_REACHED,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_DBG_MAX_HANG_STAGE_REACHED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_DBG_MAX_HANG_STAGE_REACHED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_DBG_MAX_HANG_STAGE_REACHED]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_DBG_MAX_HANG_STAGE_REACHED]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_DBG_MAX_HANG_STAGE_REACHED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_DBG_MAX_HANG_STAGE_REACHED,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_DBG_MAX_HANG_STAGE_REACHED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_DBG_MAX_HANG_STAGE_REACHED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_DBG_MAX_HANG_STAGE_REACHED]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_DBG_MAX_HANG_STAGE_REACHED]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_DBG_MAX_HANG_STAGE_REACHED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_DBG_MAX_HANG_STAGE_REACHED,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_DBG_MAX_HANG_STAGE_REACHED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_DBG_MAX_HANG_STAGE_REACHED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_STATION_DBG_MAX_HANG_STAGE_REACHED]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HOP_MODE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PUMP_MODE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REPRO_MODE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_HNG_CHK_DISABLE]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_DBG_CLR_MAX_HANG_STAGE]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SW_AB_WAIT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SW_AB_WAIT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SW_AB_WAIT_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SW_AB_WAIT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SW_AB_WAIT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SW_AB_WAIT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SW_AB_WAIT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SW_AB_WAIT_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SW_AB_WAIT_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SW_AB_WAIT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SW_AB_WAIT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SW_AB_WAIT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SW_AB_WAIT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SW_AB_WAIT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SW_AB_WAIT_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SW_AB_WAIT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SW_AB_WAIT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SW_AB_WAIT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SP_HW_MARK_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SP_HW_MARK_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SP_HW_MARK_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SP_HW_MARK_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SP_HW_MARK_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SP_HW_MARK_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SP_HW_MARK_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SP_HW_MARK_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SP_HW_MARK_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SP_HW_MARK_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SP_HW_MARK_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SP_HW_MARK_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SP_HW_MARK_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SP_HW_MARK_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SP_HW_MARK_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SP_HW_MARK_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SP_HW_MARK_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SP_HW_MARK_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_GP_HW_MARK_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_GP_HW_MARK_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_GP_HW_MARK_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_GP_HW_MARK_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_GP_HW_MARK_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_GP_HW_MARK_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_GP_HW_MARK_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_GP_HW_MARK_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_GP_HW_MARK_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_GP_HW_MARK_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_GP_HW_MARK_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_GP_HW_MARK_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_GP_HW_MARK_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_GP_HW_MARK_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_GP_HW_MARK_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_GP_HW_MARK_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_GP_HW_MARK_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_GP_HW_MARK_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NP_HW_MARK_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NP_HW_MARK_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NP_HW_MARK_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NP_HW_MARK_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NP_HW_MARK_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NP_HW_MARK_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NP_HW_MARK_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NP_HW_MARK_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NP_HW_MARK_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NP_HW_MARK_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NP_HW_MARK_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NP_HW_MARK_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NP_HW_MARK_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NP_HW_MARK_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NP_HW_MARK_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NP_HW_MARK_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NP_HW_MARK_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_NP_HW_MARK_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_SEL_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_SEL_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_SEL_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_SEL_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_SEL_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_SEL_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_SEL_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_SEL_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_SEL_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_SEL_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_SEL_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_SEL_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_SEL_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_SEL_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_SEL_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_SEL_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_SEL_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_MCA_RATIO_SEL_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_SEL_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_SEL_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_SEL_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_SEL_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_SEL_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_SEL_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_SEL_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_SEL_EQ0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_SEL_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_SEL_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_SEL_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_SEL_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_SEL_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_SEL_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_SEL_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_SEL_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_SEL_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_STEP_SEL_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_EQ0,
           PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_EQ0]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
