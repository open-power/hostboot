/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00060.H $         */
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

#ifndef __PROC_REG00060_H_
#define __PROC_REG00060_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[INT_PC_NXC_REGS_FLUSH_CTRL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_FLUSH_CTRL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_NXC_REGS_FLUSH_CTRL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[INT_PC_NXC_REGS_FLUSH_CTRL]

//>> GET_[INT_PC_NXC_REGS_FLUSH_CTRL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_FLUSH_CTRL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_NXC_REGS_FLUSH_CTRL;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_FLUSH_CTRL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[INT_PC_NXC_REGS_FLUSH_CTRL]

//>> PUT_[INT_PC_NXC_REGS_FLUSH_CTRL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_FLUSH_CTRL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_FLUSH_CTRL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[INT_PC_NXC_REGS_FLUSH_CTRL]


//>> SET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID]

//>> SET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID]

//>> SET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID]

//>> CLEAR_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID]

//>> GET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID]

//>> GET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID]
static inline bool GET_INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_VALID]

//>> SET_[INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1]

//>> SET_[INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1]

//>> SET_[INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1]

//>> CLEAR_[INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1]

//>> GET_[INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1]

//>> GET_[INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1]
static inline bool GET_INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_1]

//>> SET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> SET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> SET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> CLEAR_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> GET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> GET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]
static inline bool GET_INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE]

//>> SET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE]

//>> SET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE]

//>> SET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE]

//>> CLEAR_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE]

//>> GET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE]

//>> GET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE]
static inline bool GET_INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_NXC_REGS_FLUSH_CTRL_POLL_WANT_INVALIDATE]

//>> SET_[INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_4_6]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_4_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_4_6,
           INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_4_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_4_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_4_6]

//>> SET_[INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_4_6]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_4_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_4_6,
           INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_4_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_4_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_4_6]

//>> GET_[INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_4_6]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_4_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_4_6,
           INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_4_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_4_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_NXC_REGS_FLUSH_CTRL_RESERVED_4_6]

//>> SET_[INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE]

//>> SET_[INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE]

//>> SET_[INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE]

//>> CLEAR_[INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE]

//>> GET_[INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE]
static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE]

//>> GET_[INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE]
static inline bool GET_INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_FLUSH_CTRL));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[INT_PC_NXC_REGS_FLUSH_CTRL_INJECT_WANT_INVALIDATE]

//>> PREP_[NX_PBI_RNG_RDELAY]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_RNG_RDELAY(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_RNG_RDELAY;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NX_PBI_RNG_RDELAY]

//>> GET_[NX_PBI_RNG_RDELAY]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_RNG_RDELAY(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_RNG_RDELAY;
#endif
    return fapi2::getScom(i_target, NX_PBI_RNG_RDELAY, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NX_PBI_RNG_RDELAY]

//>> PUT_[NX_PBI_RNG_RDELAY]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_RNG_RDELAY(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_RDELAY));
#endif
    return fapi2::putScom(i_target, NX_PBI_RNG_RDELAY, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NX_PBI_RNG_RDELAY]


//>> SET_[NX_PBI_RNG_RDELAY_FILL_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_RDELAY_FILL_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_RDELAY));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_RDELAY_FILL_THRESHOLD,
           NX_PBI_RNG_RDELAY_FILL_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_RDELAY_FILL_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_RDELAY_FILL_THRESHOLD]

//>> SET_[NX_PBI_RNG_RDELAY_FILL_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_RDELAY_FILL_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_RDELAY));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_RDELAY_FILL_THRESHOLD,
           NX_PBI_RNG_RDELAY_FILL_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_RDELAY_FILL_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_RDELAY_FILL_THRESHOLD]

//>> GET_[NX_PBI_RNG_RDELAY_FILL_THRESHOLD]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_RDELAY_FILL_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_RDELAY));
#endif
    return i_data.extractToRight<NX_PBI_RNG_RDELAY_FILL_THRESHOLD,
           NX_PBI_RNG_RDELAY_FILL_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_RDELAY_FILL_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_RDELAY_FILL_THRESHOLD]

//>> SET_[NX_PBI_RNG_RDELAY_DRAIN_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_RDELAY_DRAIN_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_RDELAY));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_RDELAY_DRAIN_THRESHOLD,
           NX_PBI_RNG_RDELAY_DRAIN_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_RDELAY_DRAIN_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_RDELAY_DRAIN_THRESHOLD]

//>> SET_[NX_PBI_RNG_RDELAY_DRAIN_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_RDELAY_DRAIN_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_RDELAY));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_RDELAY_DRAIN_THRESHOLD,
           NX_PBI_RNG_RDELAY_DRAIN_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_RDELAY_DRAIN_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_RDELAY_DRAIN_THRESHOLD]

//>> GET_[NX_PBI_RNG_RDELAY_DRAIN_THRESHOLD]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_RDELAY_DRAIN_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_RDELAY));
#endif
    return i_data.extractToRight<NX_PBI_RNG_RDELAY_DRAIN_THRESHOLD,
           NX_PBI_RNG_RDELAY_DRAIN_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_RDELAY_DRAIN_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_RDELAY_DRAIN_THRESHOLD]

//>> SET_[NX_PBI_RNG_RDELAY_LFSR_RESEED_EN]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_RDELAY_LFSR_RESEED_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_RDELAY));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_RDELAY_LFSR_RESEED_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_RDELAY_LFSR_RESEED_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_RDELAY_LFSR_RESEED_EN]

//>> SET_[NX_PBI_RNG_RDELAY_LFSR_RESEED_EN]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_RDELAY_LFSR_RESEED_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_RDELAY));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_RDELAY_LFSR_RESEED_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_RDELAY_LFSR_RESEED_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_RDELAY_LFSR_RESEED_EN]

//>> SET_[NX_PBI_RNG_RDELAY_LFSR_RESEED_EN]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_RDELAY_LFSR_RESEED_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_RDELAY));
#endif
    return o_data.setBit<NX_PBI_RNG_RDELAY_LFSR_RESEED_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access NX_PBI_RNG_RDELAY_LFSR_RESEED_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_RDELAY_LFSR_RESEED_EN]

//>> CLEAR_[NX_PBI_RNG_RDELAY_LFSR_RESEED_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_RDELAY_LFSR_RESEED_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_RDELAY));
#endif
    return o_data.clearBit<NX_PBI_RNG_RDELAY_LFSR_RESEED_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access NX_PBI_RNG_RDELAY_LFSR_RESEED_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NX_PBI_RNG_RDELAY_LFSR_RESEED_EN]

//>> GET_[NX_PBI_RNG_RDELAY_LFSR_RESEED_EN]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_RDELAY_LFSR_RESEED_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_RDELAY));
#endif
    return i_data.extractToRight<NX_PBI_RNG_RDELAY_LFSR_RESEED_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_RDELAY_LFSR_RESEED_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_RDELAY_LFSR_RESEED_EN]

//>> GET_[NX_PBI_RNG_RDELAY_LFSR_RESEED_EN]
static inline bool GET_NX_PBI_RNG_RDELAY_LFSR_RESEED_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_RDELAY));
#endif
    return i_data.getBit<NX_PBI_RNG_RDELAY_LFSR_RESEED_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access NX_PBI_RNG_RDELAY_LFSR_RESEED_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_RDELAY_LFSR_RESEED_EN]

//>> SET_[NX_PBI_RNG_RDELAY_READ_RTY_RATIO]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_RDELAY_READ_RTY_RATIO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_RDELAY));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_RDELAY_READ_RTY_RATIO,
           NX_PBI_RNG_RDELAY_READ_RTY_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access NX_PBI_RNG_RDELAY_READ_RTY_RATIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_RDELAY_READ_RTY_RATIO]

//>> SET_[NX_PBI_RNG_RDELAY_READ_RTY_RATIO]
static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_RDELAY_READ_RTY_RATIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_RDELAY));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_RDELAY_READ_RTY_RATIO,
           NX_PBI_RNG_RDELAY_READ_RTY_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access NX_PBI_RNG_RDELAY_READ_RTY_RATIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NX_PBI_RNG_RDELAY_READ_RTY_RATIO]

//>> GET_[NX_PBI_RNG_RDELAY_READ_RTY_RATIO]
static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_RDELAY_READ_RTY_RATIO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_RDELAY));
#endif
    return i_data.extractToRight<NX_PBI_RNG_RDELAY_READ_RTY_RATIO,
           NX_PBI_RNG_RDELAY_READ_RTY_RATIO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access NX_PBI_RNG_RDELAY_READ_RTY_RATIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NX_PBI_RNG_RDELAY_READ_RTY_RATIO]

//>> PREP_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK]

//>> PUT_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK]


//>> SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK_HTMSC_STOP_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK_HTMSC_STOP_ADDR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK_HTMSC_STOP_ADDR_MASK,
           PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK_HTMSC_STOP_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK_HTMSC_STOP_ADDR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK_HTMSC_STOP_ADDR_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK_HTMSC_STOP_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK_HTMSC_STOP_ADDR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK_HTMSC_STOP_ADDR_MASK,
           PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK_HTMSC_STOP_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK_HTMSC_STOP_ADDR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK_HTMSC_STOP_ADDR_MASK]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK_HTMSC_STOP_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK_HTMSC_STOP_ADDR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK_HTMSC_STOP_ADDR_MASK,
           PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK_HTMSC_STOP_ADDR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK_HTMSC_STOP_ADDR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK_HTMSC_STOP_ADDR_MASK]

//>> PREP_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT]

//>> PUT_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT]


//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0]

//>> CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0]
static inline bool GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_VALID_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_EQ0]

//>> SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_EQ0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_EQ0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_EQ0]

//>> GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_EQ0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_EQ0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_EQ0,
           PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_EQ0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_EQ0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_EQ0]

//>> PREP_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR]

//>> PUT_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR]


//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_VALID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_0_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_1_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_2_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_3_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_4_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_5_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_6_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_7_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_8_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_9_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_10_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_11_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_12_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_13_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_14_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR_15_AX_NUM_CURR_ES3]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
