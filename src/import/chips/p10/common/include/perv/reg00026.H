/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00026.H $         */
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

#ifndef __PERV_REG00026_H_
#define __PERV_REG00026_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> PREP_[CTRL_ATOMIC_LOCK_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTRL_ATOMIC_LOCK_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTRL_ATOMIC_LOCK_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CTRL_ATOMIC_LOCK_REG]

//>> GET_[CTRL_ATOMIC_LOCK_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTRL_ATOMIC_LOCK_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTRL_ATOMIC_LOCK_REG;
#endif
    return fapi2::getScom(i_target, CTRL_ATOMIC_LOCK_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CTRL_ATOMIC_LOCK_REG]

//>> PUT_[CTRL_ATOMIC_LOCK_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTRL_ATOMIC_LOCK_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTRL_ATOMIC_LOCK_REG));
#endif
    return fapi2::putScom(i_target, CTRL_ATOMIC_LOCK_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CTRL_ATOMIC_LOCK_REG]


//>> SET_[CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTRL_ATOMIC_LOCK_REG));
#endif
    return o_data.insertFromRight<CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE]

//>> SET_[CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTRL_ATOMIC_LOCK_REG));
#endif
    return o_data.insertFromRight<CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE]

//>> SET_[CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTRL_ATOMIC_LOCK_REG));
#endif
    return o_data.setBit<CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE]

//>> CLEAR_[CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTRL_ATOMIC_LOCK_REG));
#endif
    return o_data.clearBit<CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE]

//>> GET_[CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTRL_ATOMIC_LOCK_REG));
#endif
    return i_data.extractToRight<CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE]

//>> GET_[CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE]
static inline bool GET_CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTRL_ATOMIC_LOCK_REG));
#endif
    return i_data.getBit<CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE]

//>> SET_[CTRL_ATOMIC_LOCK_REG_ID]
static inline fapi2::buffer<uint64_t>& SET_CTRL_ATOMIC_LOCK_REG_ID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTRL_ATOMIC_LOCK_REG));
#endif
    return o_data.insertFromRight<CTRL_ATOMIC_LOCK_REG_ID,
           CTRL_ATOMIC_LOCK_REG_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CTRL_ATOMIC_LOCK_REG_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTRL_ATOMIC_LOCK_REG_ID]

//>> SET_[CTRL_ATOMIC_LOCK_REG_ID]
static inline fapi2::buffer<uint64_t>& SET_CTRL_ATOMIC_LOCK_REG_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTRL_ATOMIC_LOCK_REG));
#endif
    return o_data.insertFromRight<CTRL_ATOMIC_LOCK_REG_ID,
           CTRL_ATOMIC_LOCK_REG_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CTRL_ATOMIC_LOCK_REG_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTRL_ATOMIC_LOCK_REG_ID]

//>> GET_[CTRL_ATOMIC_LOCK_REG_ID]
static inline fapi2::buffer<uint64_t>& GET_CTRL_ATOMIC_LOCK_REG_ID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTRL_ATOMIC_LOCK_REG));
#endif
    return i_data.extractToRight<CTRL_ATOMIC_LOCK_REG_ID,
           CTRL_ATOMIC_LOCK_REG_ID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CTRL_ATOMIC_LOCK_REG_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTRL_ATOMIC_LOCK_REG_ID]

//>> SET_[CTRL_ATOMIC_LOCK_REG_ACTIVITY]
static inline fapi2::buffer<uint64_t>& SET_CTRL_ATOMIC_LOCK_REG_ACTIVITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTRL_ATOMIC_LOCK_REG));
#endif
    return o_data.insertFromRight<CTRL_ATOMIC_LOCK_REG_ACTIVITY,
           CTRL_ATOMIC_LOCK_REG_ACTIVITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CTRL_ATOMIC_LOCK_REG_ACTIVITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTRL_ATOMIC_LOCK_REG_ACTIVITY]

//>> SET_[CTRL_ATOMIC_LOCK_REG_ACTIVITY]
static inline fapi2::buffer<uint64_t>& SET_CTRL_ATOMIC_LOCK_REG_ACTIVITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTRL_ATOMIC_LOCK_REG));
#endif
    return o_data.insertFromRight<CTRL_ATOMIC_LOCK_REG_ACTIVITY,
           CTRL_ATOMIC_LOCK_REG_ACTIVITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CTRL_ATOMIC_LOCK_REG_ACTIVITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTRL_ATOMIC_LOCK_REG_ACTIVITY]

//>> GET_[CTRL_ATOMIC_LOCK_REG_ACTIVITY]
static inline fapi2::buffer<uint64_t>& GET_CTRL_ATOMIC_LOCK_REG_ACTIVITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTRL_ATOMIC_LOCK_REG));
#endif
    return i_data.extractToRight<CTRL_ATOMIC_LOCK_REG_ACTIVITY,
           CTRL_ATOMIC_LOCK_REG_ACTIVITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CTRL_ATOMIC_LOCK_REG_ACTIVITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTRL_ATOMIC_LOCK_REG_ACTIVITY]

//>> PREP_[EPS_DBG_DEBUG_TRACE_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_DBG_DEBUG_TRACE_CONTROL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    scomt::last_scom = EPS_DBG_DEBUG_TRACE_CONTROL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_DBG_DEBUG_TRACE_CONTROL]

//>> GET_[EPS_DBG_DEBUG_TRACE_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_DBG_DEBUG_TRACE_CONTROL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    scomt::last_scom = EPS_DBG_DEBUG_TRACE_CONTROL;
#endif
    return fapi2::getScom(i_target, EPS_DBG_DEBUG_TRACE_CONTROL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_DBG_DEBUG_TRACE_CONTROL]

//>> PUT_[EPS_DBG_DEBUG_TRACE_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_DBG_DEBUG_TRACE_CONTROL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return fapi2::putScom(i_target, EPS_DBG_DEBUG_TRACE_CONTROL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_DBG_DEBUG_TRACE_CONTROL]


//>> SET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START]

//>> SET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START]

//>> SET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return o_data.setBit<P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START]

//>> CLEAR_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return o_data.clearBit<P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START]

//>> GET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return i_data.extractToRight<P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START]

//>> GET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START]
static inline bool GET_P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return i_data.getBit<P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START]

//>> SET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP]

//>> SET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP]

//>> SET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return o_data.setBit<P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP]

//>> CLEAR_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return o_data.clearBit<P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP]

//>> GET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return i_data.extractToRight<P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP]

//>> GET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP]
static inline bool GET_P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return i_data.getBit<P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP]

//>> SET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET]

//>> SET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET]

//>> SET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return o_data.setBit<P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET]

//>> CLEAR_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return o_data.clearBit<P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET]

//>> GET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return i_data.extractToRight<P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET]

//>> GET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET]
static inline bool GET_P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return i_data.getBit<P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_RW]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_RW]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_RW]


//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_ROOT_CTRL0_COPY_REG]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_ROOT_CTRL0_COPY_REG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_ROOT_CTRL0_COPY_REG,
           FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_ROOT_CTRL0_COPY_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_ROOT_CTRL0_COPY_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_ROOT_CTRL0_COPY_REG]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_ROOT_CTRL0_COPY_REG]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_ROOT_CTRL0_COPY_REG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_ROOT_CTRL0_COPY_REG,
           FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_ROOT_CTRL0_COPY_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_ROOT_CTRL0_COPY_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_ROOT_CTRL0_COPY_REG]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_ROOT_CTRL0_COPY_REG]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_ROOT_CTRL0_COPY_REG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_ROOT_CTRL0_COPY_REG,
           FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_ROOT_CTRL0_COPY_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_ROOT_CTRL0_COPY_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_ROOT_CTRL0_COPY_REG]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL5_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL5_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL5_FSI]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL5_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_FSI]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL5_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL5_FSI]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL5_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL5_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL5_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL5_RW]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL5_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL5_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL5_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_RW]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL5_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL5_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL5_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL5_RW]


//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW,
           FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW,
           FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW,
           FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_FILT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_FILT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_FILT,
           FSXCOMP_FSXLOG_ROOT_CTRL5_FILT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_FILT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_FILT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_FILT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_FILT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_FILT,
           FSXCOMP_FSXLOG_ROOT_CTRL5_FILT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_FILT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_FILT]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_FILT]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_FILT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_FILT,
           FSXCOMP_FSXLOG_ROOT_CTRL5_FILT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_FILT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_FILT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL,
           FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL,
           FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL,
           FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT,
           FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT,
           FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT,
           FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL5_RW));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT]

//>> PREP_[FSXCOMP_FSXLOG_SB_MSG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SB_MSG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SB_MSG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SB_MSG]

//>> GET_[FSXCOMP_FSXLOG_SB_MSG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SB_MSG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SB_MSG;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SB_MSG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SB_MSG]

//>> PUT_[FSXCOMP_FSXLOG_SB_MSG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SB_MSG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_MSG, FSXCOMP_FSXLOG_SB_MSG_FSI, FSXCOMP_FSXLOG_SB_MSG_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SB_MSG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SB_MSG]

//>> PREP_[FSXCOMP_FSXLOG_SB_MSG_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SB_MSG_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SB_MSG_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SB_MSG_FSI]

//>> GET_[FSXCOMP_FSXLOG_SB_MSG_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SB_MSG_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SB_MSG_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SB_MSG_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SB_MSG_FSI]

//>> PUT_[FSXCOMP_FSXLOG_SB_MSG_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SB_MSG_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_MSG, FSXCOMP_FSXLOG_SB_MSG_FSI, FSXCOMP_FSXLOG_SB_MSG_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SB_MSG_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SB_MSG_FSI]

//>> PREP_[FSXCOMP_FSXLOG_SB_MSG_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SB_MSG_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SB_MSG_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SB_MSG_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_SB_MSG_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SB_MSG_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SB_MSG_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SB_MSG_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SB_MSG_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_SB_MSG_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SB_MSG_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_MSG, FSXCOMP_FSXLOG_SB_MSG_FSI, FSXCOMP_FSXLOG_SB_MSG_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SB_MSG_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SB_MSG_FSI_BYTE]


//>> PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI]

//>> PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI]

//>> PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_RW]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_RW]

//>> PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_RW]


//>> SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_SR_SCRATCH_REGISTER_1]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_SR_SCRATCH_REGISTER_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_SR_SCRATCH_REGISTER_1,
           FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_SR_SCRATCH_REGISTER_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_SR_SCRATCH_REGISTER_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_SR_SCRATCH_REGISTER_1]

//>> SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_SR_SCRATCH_REGISTER_1]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_SR_SCRATCH_REGISTER_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_SR_SCRATCH_REGISTER_1,
           FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_SR_SCRATCH_REGISTER_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_SR_SCRATCH_REGISTER_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_SR_SCRATCH_REGISTER_1]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_SR_SCRATCH_REGISTER_1]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_SR_SCRATCH_REGISTER_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_SR_SCRATCH_REGISTER_1,
           FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_SR_SCRATCH_REGISTER_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_SR_SCRATCH_REGISTER_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_SR_SCRATCH_REGISTER_1]

//>> PREP_[OPCG_CAPT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_OPCG_CAPT1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OPCG_CAPT1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[OPCG_CAPT1]

//>> GET_[OPCG_CAPT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_OPCG_CAPT1(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OPCG_CAPT1;
#endif
    return fapi2::getScom(i_target, OPCG_CAPT1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[OPCG_CAPT1]

//>> PUT_[OPCG_CAPT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_OPCG_CAPT1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return fapi2::putScom(i_target, OPCG_CAPT1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[OPCG_CAPT1]


//>> SET_[OPCG_CAPT1_COUNT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_COUNT,
           OPCG_CAPT1_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT1_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_COUNT]

//>> SET_[OPCG_CAPT1_COUNT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_COUNT,
           OPCG_CAPT1_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT1_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_COUNT]

//>> GET_[OPCG_CAPT1_COUNT]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT1_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return i_data.extractToRight<OPCG_CAPT1_COUNT,
           OPCG_CAPT1_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT1_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT1_COUNT]

//>> SET_[OPCG_CAPT1_SEQ_01]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_SEQ_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_SEQ_01,
           OPCG_CAPT1_SEQ_01_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT1_SEQ_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_SEQ_01]

//>> SET_[OPCG_CAPT1_SEQ_01]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_SEQ_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_SEQ_01,
           OPCG_CAPT1_SEQ_01_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT1_SEQ_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_SEQ_01]

//>> GET_[OPCG_CAPT1_SEQ_01]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT1_SEQ_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return i_data.extractToRight<OPCG_CAPT1_SEQ_01,
           OPCG_CAPT1_SEQ_01_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT1_SEQ_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT1_SEQ_01]

//>> SET_[OPCG_CAPT1_SEQ_02]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_SEQ_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_SEQ_02,
           OPCG_CAPT1_SEQ_02_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT1_SEQ_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_SEQ_02]

//>> SET_[OPCG_CAPT1_SEQ_02]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_SEQ_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_SEQ_02,
           OPCG_CAPT1_SEQ_02_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT1_SEQ_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_SEQ_02]

//>> GET_[OPCG_CAPT1_SEQ_02]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT1_SEQ_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return i_data.extractToRight<OPCG_CAPT1_SEQ_02,
           OPCG_CAPT1_SEQ_02_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT1_SEQ_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT1_SEQ_02]

//>> SET_[OPCG_CAPT1_SEQ_03]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_SEQ_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_SEQ_03,
           OPCG_CAPT1_SEQ_03_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT1_SEQ_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_SEQ_03]

//>> SET_[OPCG_CAPT1_SEQ_03]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_SEQ_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_SEQ_03,
           OPCG_CAPT1_SEQ_03_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT1_SEQ_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_SEQ_03]

//>> GET_[OPCG_CAPT1_SEQ_03]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT1_SEQ_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return i_data.extractToRight<OPCG_CAPT1_SEQ_03,
           OPCG_CAPT1_SEQ_03_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT1_SEQ_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT1_SEQ_03]

//>> SET_[OPCG_CAPT1_SEQ_04]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_SEQ_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_SEQ_04,
           OPCG_CAPT1_SEQ_04_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT1_SEQ_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_SEQ_04]

//>> SET_[OPCG_CAPT1_SEQ_04]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_SEQ_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_SEQ_04,
           OPCG_CAPT1_SEQ_04_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT1_SEQ_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_SEQ_04]

//>> GET_[OPCG_CAPT1_SEQ_04]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT1_SEQ_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return i_data.extractToRight<OPCG_CAPT1_SEQ_04,
           OPCG_CAPT1_SEQ_04_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT1_SEQ_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT1_SEQ_04]

//>> SET_[OPCG_CAPT1_SEQ_05]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_SEQ_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_SEQ_05,
           OPCG_CAPT1_SEQ_05_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT1_SEQ_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_SEQ_05]

//>> SET_[OPCG_CAPT1_SEQ_05]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_SEQ_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_SEQ_05,
           OPCG_CAPT1_SEQ_05_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT1_SEQ_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_SEQ_05]

//>> GET_[OPCG_CAPT1_SEQ_05]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT1_SEQ_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return i_data.extractToRight<OPCG_CAPT1_SEQ_05,
           OPCG_CAPT1_SEQ_05_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT1_SEQ_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT1_SEQ_05]

//>> SET_[OPCG_CAPT1_SEQ_06]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_SEQ_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_SEQ_06,
           OPCG_CAPT1_SEQ_06_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT1_SEQ_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_SEQ_06]

//>> SET_[OPCG_CAPT1_SEQ_06]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_SEQ_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_SEQ_06,
           OPCG_CAPT1_SEQ_06_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT1_SEQ_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_SEQ_06]

//>> GET_[OPCG_CAPT1_SEQ_06]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT1_SEQ_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return i_data.extractToRight<OPCG_CAPT1_SEQ_06,
           OPCG_CAPT1_SEQ_06_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT1_SEQ_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT1_SEQ_06]

//>> SET_[OPCG_CAPT1_SEQ_07]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_SEQ_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_SEQ_07,
           OPCG_CAPT1_SEQ_07_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT1_SEQ_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_SEQ_07]

//>> SET_[OPCG_CAPT1_SEQ_07]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_SEQ_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_SEQ_07,
           OPCG_CAPT1_SEQ_07_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT1_SEQ_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_SEQ_07]

//>> GET_[OPCG_CAPT1_SEQ_07]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT1_SEQ_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return i_data.extractToRight<OPCG_CAPT1_SEQ_07,
           OPCG_CAPT1_SEQ_07_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT1_SEQ_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT1_SEQ_07]

//>> SET_[OPCG_CAPT1_SEQ_08]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_SEQ_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_SEQ_08,
           OPCG_CAPT1_SEQ_08_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT1_SEQ_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_SEQ_08]

//>> SET_[OPCG_CAPT1_SEQ_08]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_SEQ_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_SEQ_08,
           OPCG_CAPT1_SEQ_08_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT1_SEQ_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_SEQ_08]

//>> GET_[OPCG_CAPT1_SEQ_08]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT1_SEQ_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return i_data.extractToRight<OPCG_CAPT1_SEQ_08,
           OPCG_CAPT1_SEQ_08_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT1_SEQ_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT1_SEQ_08]

//>> SET_[OPCG_CAPT1_SEQ_09]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_SEQ_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_SEQ_09,
           OPCG_CAPT1_SEQ_09_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT1_SEQ_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_SEQ_09]

//>> SET_[OPCG_CAPT1_SEQ_09]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_SEQ_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_SEQ_09,
           OPCG_CAPT1_SEQ_09_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT1_SEQ_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_SEQ_09]

//>> GET_[OPCG_CAPT1_SEQ_09]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT1_SEQ_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return i_data.extractToRight<OPCG_CAPT1_SEQ_09,
           OPCG_CAPT1_SEQ_09_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT1_SEQ_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT1_SEQ_09]

//>> SET_[OPCG_CAPT1_SEQ_10]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_SEQ_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_SEQ_10,
           OPCG_CAPT1_SEQ_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT1_SEQ_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_SEQ_10]

//>> SET_[OPCG_CAPT1_SEQ_10]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_SEQ_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_SEQ_10,
           OPCG_CAPT1_SEQ_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT1_SEQ_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_SEQ_10]

//>> GET_[OPCG_CAPT1_SEQ_10]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT1_SEQ_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return i_data.extractToRight<OPCG_CAPT1_SEQ_10,
           OPCG_CAPT1_SEQ_10_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT1_SEQ_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT1_SEQ_10]

//>> SET_[OPCG_CAPT1_SEQ_11]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_SEQ_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_SEQ_11,
           OPCG_CAPT1_SEQ_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT1_SEQ_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_SEQ_11]

//>> SET_[OPCG_CAPT1_SEQ_11]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_SEQ_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_SEQ_11,
           OPCG_CAPT1_SEQ_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT1_SEQ_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_SEQ_11]

//>> GET_[OPCG_CAPT1_SEQ_11]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT1_SEQ_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return i_data.extractToRight<OPCG_CAPT1_SEQ_11,
           OPCG_CAPT1_SEQ_11_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT1_SEQ_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT1_SEQ_11]

//>> SET_[OPCG_CAPT1_SEQ_12]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_SEQ_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_SEQ_12,
           OPCG_CAPT1_SEQ_12_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access OPCG_CAPT1_SEQ_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_SEQ_12]

//>> SET_[OPCG_CAPT1_SEQ_12]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT1_SEQ_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return o_data.insertFromRight<OPCG_CAPT1_SEQ_12,
           OPCG_CAPT1_SEQ_12_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access OPCG_CAPT1_SEQ_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT1_SEQ_12]

//>> GET_[OPCG_CAPT1_SEQ_12]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT1_SEQ_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT1));
#endif
    return i_data.extractToRight<OPCG_CAPT1_SEQ_12,
           OPCG_CAPT1_SEQ_12_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access OPCG_CAPT1_SEQ_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT1_SEQ_12]

//>> PREP_[RECOV_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RECOV_MASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RECOV_MASK_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RECOV_MASK_RW]

//>> GET_[RECOV_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RECOV_MASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RECOV_MASK_RW;
#endif
    return fapi2::getScom(i_target, RECOV_MASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RECOV_MASK_RW]

//>> PUT_[RECOV_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RECOV_MASK_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, RECOV_MASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RECOV_MASK_RW]

//>> PREP_[RECOV_MASK_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RECOV_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RECOV_MASK_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RECOV_MASK_WO_CLEAR]

//>> GET_[RECOV_MASK_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RECOV_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RECOV_MASK_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, RECOV_MASK_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RECOV_MASK_WO_CLEAR]

//>> PUT_[RECOV_MASK_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RECOV_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, RECOV_MASK_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RECOV_MASK_WO_CLEAR]

//>> PREP_[RECOV_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RECOV_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RECOV_MASK_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RECOV_MASK_WO_OR]

//>> GET_[RECOV_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RECOV_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RECOV_MASK_WO_OR;
#endif
    return fapi2::getScom(i_target, RECOV_MASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RECOV_MASK_WO_OR]

//>> PUT_[RECOV_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RECOV_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, RECOV_MASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RECOV_MASK_WO_OR]


//>> SET_[RECOV_MASK_1]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_1]

//>> SET_[RECOV_MASK_1]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_1]

//>> SET_[RECOV_MASK_1]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_1]

//>> CLEAR_[RECOV_MASK_1]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_1]

//>> GET_[RECOV_MASK_1]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_1]

//>> GET_[RECOV_MASK_1]
static inline bool GET_RECOV_MASK_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_1]

//>> SET_[RECOV_MASK_2]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_2]

//>> SET_[RECOV_MASK_2]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_2]

//>> SET_[RECOV_MASK_2]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_2]

//>> CLEAR_[RECOV_MASK_2]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_2]

//>> GET_[RECOV_MASK_2]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_2]

//>> GET_[RECOV_MASK_2]
static inline bool GET_RECOV_MASK_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_2]

//>> SET_[RECOV_MASK_3]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_3]

//>> SET_[RECOV_MASK_3]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_3]

//>> SET_[RECOV_MASK_3]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_3]

//>> CLEAR_[RECOV_MASK_3]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_3]

//>> GET_[RECOV_MASK_3]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_3]

//>> GET_[RECOV_MASK_3]
static inline bool GET_RECOV_MASK_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_3]

//>> SET_[RECOV_MASK_4]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_4]

//>> SET_[RECOV_MASK_4]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_4]

//>> SET_[RECOV_MASK_4]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_4]

//>> CLEAR_[RECOV_MASK_4]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_4]

//>> GET_[RECOV_MASK_4]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_4]

//>> GET_[RECOV_MASK_4]
static inline bool GET_RECOV_MASK_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_4]

//>> SET_[RECOV_MASK_5]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_5]

//>> SET_[RECOV_MASK_5]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_5]

//>> SET_[RECOV_MASK_5]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_5]

//>> CLEAR_[RECOV_MASK_5]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_5]

//>> GET_[RECOV_MASK_5]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_5]

//>> GET_[RECOV_MASK_5]
static inline bool GET_RECOV_MASK_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_5]

//>> SET_[RECOV_MASK_6]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_6]

//>> SET_[RECOV_MASK_6]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_6]

//>> SET_[RECOV_MASK_6]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_6]

//>> CLEAR_[RECOV_MASK_6]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_6]

//>> GET_[RECOV_MASK_6]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_6]

//>> GET_[RECOV_MASK_6]
static inline bool GET_RECOV_MASK_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_6]

//>> SET_[RECOV_MASK_7]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_7]

//>> SET_[RECOV_MASK_7]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_7]

//>> SET_[RECOV_MASK_7]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_7]

//>> CLEAR_[RECOV_MASK_7]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_7]

//>> GET_[RECOV_MASK_7]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_7]

//>> GET_[RECOV_MASK_7]
static inline bool GET_RECOV_MASK_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_7]

//>> SET_[RECOV_MASK_8]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_8]

//>> SET_[RECOV_MASK_8]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_8]

//>> SET_[RECOV_MASK_8]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_8]

//>> CLEAR_[RECOV_MASK_8]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_8]

//>> GET_[RECOV_MASK_8]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_8]

//>> GET_[RECOV_MASK_8]
static inline bool GET_RECOV_MASK_8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_8]

//>> SET_[RECOV_MASK_9]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_9]

//>> SET_[RECOV_MASK_9]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_9]

//>> SET_[RECOV_MASK_9]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_9]

//>> CLEAR_[RECOV_MASK_9]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_9]

//>> GET_[RECOV_MASK_9]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_9]

//>> GET_[RECOV_MASK_9]
static inline bool GET_RECOV_MASK_9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_9]

//>> SET_[RECOV_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_10]

//>> SET_[RECOV_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_10]

//>> SET_[RECOV_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_10]

//>> CLEAR_[RECOV_MASK_10]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_10]

//>> GET_[RECOV_MASK_10]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_10]

//>> GET_[RECOV_MASK_10]
static inline bool GET_RECOV_MASK_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_10]

//>> SET_[RECOV_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_11]

//>> SET_[RECOV_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_11]

//>> SET_[RECOV_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_11]

//>> CLEAR_[RECOV_MASK_11]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_11]

//>> GET_[RECOV_MASK_11]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_11]

//>> GET_[RECOV_MASK_11]
static inline bool GET_RECOV_MASK_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_11]

//>> SET_[RECOV_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_12]

//>> SET_[RECOV_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_12]

//>> SET_[RECOV_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_12]

//>> CLEAR_[RECOV_MASK_12]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_12]

//>> GET_[RECOV_MASK_12]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_12]

//>> GET_[RECOV_MASK_12]
static inline bool GET_RECOV_MASK_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_12]

//>> SET_[RECOV_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_13]

//>> SET_[RECOV_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_13]

//>> SET_[RECOV_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_13]

//>> CLEAR_[RECOV_MASK_13]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_13]

//>> GET_[RECOV_MASK_13]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_13]

//>> GET_[RECOV_MASK_13]
static inline bool GET_RECOV_MASK_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_13]

//>> SET_[RECOV_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_14]

//>> SET_[RECOV_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_14]

//>> SET_[RECOV_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_14]

//>> CLEAR_[RECOV_MASK_14]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_14]

//>> GET_[RECOV_MASK_14]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_14]

//>> GET_[RECOV_MASK_14]
static inline bool GET_RECOV_MASK_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_14]

//>> SET_[RECOV_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_15]

//>> SET_[RECOV_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_15]

//>> SET_[RECOV_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_15]

//>> CLEAR_[RECOV_MASK_15]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_15]

//>> GET_[RECOV_MASK_15]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_15]

//>> GET_[RECOV_MASK_15]
static inline bool GET_RECOV_MASK_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_15]

//>> SET_[RECOV_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_16]

//>> SET_[RECOV_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_16]

//>> SET_[RECOV_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_16]

//>> CLEAR_[RECOV_MASK_16]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_16]

//>> GET_[RECOV_MASK_16]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_16]

//>> GET_[RECOV_MASK_16]
static inline bool GET_RECOV_MASK_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_16]

//>> SET_[RECOV_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_17]

//>> SET_[RECOV_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_17]

//>> SET_[RECOV_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_17]

//>> CLEAR_[RECOV_MASK_17]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_17]

//>> GET_[RECOV_MASK_17]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_17]

//>> GET_[RECOV_MASK_17]
static inline bool GET_RECOV_MASK_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_17]

//>> SET_[RECOV_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_18]

//>> SET_[RECOV_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_18]

//>> SET_[RECOV_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_18]

//>> CLEAR_[RECOV_MASK_18]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_18]

//>> GET_[RECOV_MASK_18]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_18]

//>> GET_[RECOV_MASK_18]
static inline bool GET_RECOV_MASK_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_18]

//>> SET_[RECOV_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_19]

//>> SET_[RECOV_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_19]

//>> SET_[RECOV_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_19]

//>> CLEAR_[RECOV_MASK_19]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_19]

//>> GET_[RECOV_MASK_19]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_19]

//>> GET_[RECOV_MASK_19]
static inline bool GET_RECOV_MASK_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_19]

//>> SET_[RECOV_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_20]

//>> SET_[RECOV_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_20]

//>> SET_[RECOV_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_20]

//>> CLEAR_[RECOV_MASK_20]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_20]

//>> GET_[RECOV_MASK_20]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_20]

//>> GET_[RECOV_MASK_20]
static inline bool GET_RECOV_MASK_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_20]

//>> SET_[RECOV_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_21]

//>> SET_[RECOV_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_21]

//>> SET_[RECOV_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_21]

//>> CLEAR_[RECOV_MASK_21]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_21]

//>> GET_[RECOV_MASK_21]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_21]

//>> GET_[RECOV_MASK_21]
static inline bool GET_RECOV_MASK_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_21]

//>> SET_[RECOV_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_22]

//>> SET_[RECOV_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_22]

//>> SET_[RECOV_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_22]

//>> CLEAR_[RECOV_MASK_22]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_22]

//>> GET_[RECOV_MASK_22]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_22]

//>> GET_[RECOV_MASK_22]
static inline bool GET_RECOV_MASK_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_22]

//>> SET_[RECOV_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_23]

//>> SET_[RECOV_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_23]

//>> SET_[RECOV_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_23]

//>> CLEAR_[RECOV_MASK_23]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_23]

//>> GET_[RECOV_MASK_23]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_23]

//>> GET_[RECOV_MASK_23]
static inline bool GET_RECOV_MASK_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_23]

//>> SET_[RECOV_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_24]

//>> SET_[RECOV_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_24]

//>> SET_[RECOV_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_24]

//>> CLEAR_[RECOV_MASK_24]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_24]

//>> GET_[RECOV_MASK_24]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_24]

//>> GET_[RECOV_MASK_24]
static inline bool GET_RECOV_MASK_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_24]

//>> SET_[RECOV_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_25]

//>> SET_[RECOV_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_25]

//>> SET_[RECOV_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_25]

//>> CLEAR_[RECOV_MASK_25]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_25]

//>> GET_[RECOV_MASK_25]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_25]

//>> GET_[RECOV_MASK_25]
static inline bool GET_RECOV_MASK_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_25]

//>> SET_[RECOV_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_26]

//>> SET_[RECOV_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_26]

//>> SET_[RECOV_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_26]

//>> CLEAR_[RECOV_MASK_26]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_26]

//>> GET_[RECOV_MASK_26]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_26]

//>> GET_[RECOV_MASK_26]
static inline bool GET_RECOV_MASK_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_26]

//>> SET_[RECOV_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_27]

//>> SET_[RECOV_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_27]

//>> SET_[RECOV_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_27]

//>> CLEAR_[RECOV_MASK_27]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_27]

//>> GET_[RECOV_MASK_27]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_27]

//>> GET_[RECOV_MASK_27]
static inline bool GET_RECOV_MASK_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_27]

//>> SET_[RECOV_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_28]

//>> SET_[RECOV_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_28]

//>> SET_[RECOV_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_28]

//>> CLEAR_[RECOV_MASK_28]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_28]

//>> GET_[RECOV_MASK_28]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_28]

//>> GET_[RECOV_MASK_28]
static inline bool GET_RECOV_MASK_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_28]

//>> SET_[RECOV_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_29]

//>> SET_[RECOV_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_29]

//>> SET_[RECOV_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_29]

//>> CLEAR_[RECOV_MASK_29]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_29]

//>> GET_[RECOV_MASK_29]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_29]

//>> GET_[RECOV_MASK_29]
static inline bool GET_RECOV_MASK_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_29]

//>> SET_[RECOV_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_30]

//>> SET_[RECOV_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_30]

//>> SET_[RECOV_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_30]

//>> CLEAR_[RECOV_MASK_30]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_30]

//>> GET_[RECOV_MASK_30]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_30]

//>> GET_[RECOV_MASK_30]
static inline bool GET_RECOV_MASK_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_30]

//>> SET_[RECOV_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_31]

//>> SET_[RECOV_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_31]

//>> SET_[RECOV_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_31]

//>> CLEAR_[RECOV_MASK_31]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_31]

//>> GET_[RECOV_MASK_31]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_31]

//>> GET_[RECOV_MASK_31]
static inline bool GET_RECOV_MASK_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_31]

//>> SET_[RECOV_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_32]

//>> SET_[RECOV_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_32]

//>> SET_[RECOV_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_32]

//>> CLEAR_[RECOV_MASK_32]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_32]

//>> GET_[RECOV_MASK_32]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_32]

//>> GET_[RECOV_MASK_32]
static inline bool GET_RECOV_MASK_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_32]

//>> SET_[RECOV_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_33]

//>> SET_[RECOV_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_33]

//>> SET_[RECOV_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_33]

//>> CLEAR_[RECOV_MASK_33]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_33]

//>> GET_[RECOV_MASK_33]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_33]

//>> GET_[RECOV_MASK_33]
static inline bool GET_RECOV_MASK_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_33]

//>> SET_[RECOV_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_34]

//>> SET_[RECOV_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_34]

//>> SET_[RECOV_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_34]

//>> CLEAR_[RECOV_MASK_34]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_34]

//>> GET_[RECOV_MASK_34]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_34]

//>> GET_[RECOV_MASK_34]
static inline bool GET_RECOV_MASK_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_34]

//>> SET_[RECOV_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_35]

//>> SET_[RECOV_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_35]

//>> SET_[RECOV_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_35]

//>> CLEAR_[RECOV_MASK_35]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_35]

//>> GET_[RECOV_MASK_35]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_35]

//>> GET_[RECOV_MASK_35]
static inline bool GET_RECOV_MASK_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_35]

//>> SET_[RECOV_MASK_36]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_36]

//>> SET_[RECOV_MASK_36]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_36]

//>> SET_[RECOV_MASK_36]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_36]

//>> CLEAR_[RECOV_MASK_36]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_36]

//>> GET_[RECOV_MASK_36]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_36]

//>> GET_[RECOV_MASK_36]
static inline bool GET_RECOV_MASK_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_36]

//>> SET_[RECOV_MASK_37]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_37]

//>> SET_[RECOV_MASK_37]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_37]

//>> SET_[RECOV_MASK_37]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_37]

//>> CLEAR_[RECOV_MASK_37]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_37]

//>> GET_[RECOV_MASK_37]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_37]

//>> GET_[RECOV_MASK_37]
static inline bool GET_RECOV_MASK_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_37]

//>> SET_[RECOV_MASK_38]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_38]

//>> SET_[RECOV_MASK_38]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_38]

//>> SET_[RECOV_MASK_38]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_38]

//>> CLEAR_[RECOV_MASK_38]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_38]

//>> GET_[RECOV_MASK_38]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_38]

//>> GET_[RECOV_MASK_38]
static inline bool GET_RECOV_MASK_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_38]

//>> SET_[RECOV_MASK_39]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_39]

//>> SET_[RECOV_MASK_39]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_39]

//>> SET_[RECOV_MASK_39]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_39]

//>> CLEAR_[RECOV_MASK_39]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_39]

//>> GET_[RECOV_MASK_39]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_39]

//>> GET_[RECOV_MASK_39]
static inline bool GET_RECOV_MASK_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_39]

//>> SET_[RECOV_MASK_40]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_40]

//>> SET_[RECOV_MASK_40]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_40]

//>> SET_[RECOV_MASK_40]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_40]

//>> CLEAR_[RECOV_MASK_40]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_40]

//>> GET_[RECOV_MASK_40]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_40]

//>> GET_[RECOV_MASK_40]
static inline bool GET_RECOV_MASK_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_40]

//>> SET_[RECOV_MASK_41]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_41]

//>> SET_[RECOV_MASK_41]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_41]

//>> SET_[RECOV_MASK_41]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_41]

//>> CLEAR_[RECOV_MASK_41]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_41]

//>> GET_[RECOV_MASK_41]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_41]

//>> GET_[RECOV_MASK_41]
static inline bool GET_RECOV_MASK_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_41]

//>> SET_[RECOV_MASK_42]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_42]

//>> SET_[RECOV_MASK_42]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_42]

//>> SET_[RECOV_MASK_42]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_42]

//>> CLEAR_[RECOV_MASK_42]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_42]

//>> GET_[RECOV_MASK_42]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_42]

//>> GET_[RECOV_MASK_42]
static inline bool GET_RECOV_MASK_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_42]

//>> SET_[RECOV_MASK_43]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_43]

//>> SET_[RECOV_MASK_43]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_43]

//>> SET_[RECOV_MASK_43]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_43]

//>> CLEAR_[RECOV_MASK_43]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_43]

//>> GET_[RECOV_MASK_43]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_43]

//>> GET_[RECOV_MASK_43]
static inline bool GET_RECOV_MASK_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_43]

//>> SET_[RECOV_MASK_44]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_44]

//>> SET_[RECOV_MASK_44]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_44]

//>> SET_[RECOV_MASK_44]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_44]

//>> CLEAR_[RECOV_MASK_44]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_44]

//>> GET_[RECOV_MASK_44]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_44]

//>> GET_[RECOV_MASK_44]
static inline bool GET_RECOV_MASK_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_44]

//>> SET_[RECOV_MASK_45]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_45]

//>> SET_[RECOV_MASK_45]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_45]

//>> SET_[RECOV_MASK_45]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_45]

//>> CLEAR_[RECOV_MASK_45]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_45]

//>> GET_[RECOV_MASK_45]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_45]

//>> GET_[RECOV_MASK_45]
static inline bool GET_RECOV_MASK_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_45]

//>> SET_[RECOV_MASK_46]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_46]

//>> SET_[RECOV_MASK_46]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_46]

//>> SET_[RECOV_MASK_46]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_46]

//>> CLEAR_[RECOV_MASK_46]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_46]

//>> GET_[RECOV_MASK_46]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_46]

//>> GET_[RECOV_MASK_46]
static inline bool GET_RECOV_MASK_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_46]

//>> SET_[RECOV_MASK_47]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_47]

//>> SET_[RECOV_MASK_47]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_47]

//>> SET_[RECOV_MASK_47]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_47]

//>> CLEAR_[RECOV_MASK_47]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_47]

//>> GET_[RECOV_MASK_47]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_47]

//>> GET_[RECOV_MASK_47]
static inline bool GET_RECOV_MASK_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_47]

//>> SET_[RECOV_MASK_48]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_48]

//>> SET_[RECOV_MASK_48]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_48]

//>> SET_[RECOV_MASK_48]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_48]

//>> CLEAR_[RECOV_MASK_48]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_48]

//>> GET_[RECOV_MASK_48]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_48]

//>> GET_[RECOV_MASK_48]
static inline bool GET_RECOV_MASK_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_48]

//>> SET_[RECOV_MASK_49]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_49]

//>> SET_[RECOV_MASK_49]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_49]

//>> SET_[RECOV_MASK_49]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_49]

//>> CLEAR_[RECOV_MASK_49]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_49]

//>> GET_[RECOV_MASK_49]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_49]

//>> GET_[RECOV_MASK_49]
static inline bool GET_RECOV_MASK_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_49]

//>> SET_[RECOV_MASK_50]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_50]

//>> SET_[RECOV_MASK_50]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_50]

//>> SET_[RECOV_MASK_50]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_50]

//>> CLEAR_[RECOV_MASK_50]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_50]

//>> GET_[RECOV_MASK_50]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_50]

//>> GET_[RECOV_MASK_50]
static inline bool GET_RECOV_MASK_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_50]

//>> SET_[RECOV_MASK_51]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_51]

//>> SET_[RECOV_MASK_51]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_51]

//>> SET_[RECOV_MASK_51]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_51]

//>> CLEAR_[RECOV_MASK_51]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_51]

//>> GET_[RECOV_MASK_51]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_51]

//>> GET_[RECOV_MASK_51]
static inline bool GET_RECOV_MASK_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_51]

//>> SET_[RECOV_MASK_52]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_52]

//>> SET_[RECOV_MASK_52]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_52]

//>> SET_[RECOV_MASK_52]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_52]

//>> CLEAR_[RECOV_MASK_52]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_52]

//>> GET_[RECOV_MASK_52]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_52]

//>> GET_[RECOV_MASK_52]
static inline bool GET_RECOV_MASK_52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_52]

//>> SET_[RECOV_MASK_53]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RECOV_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_53]

//>> SET_[RECOV_MASK_53]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.insertFromRight<RECOV_MASK_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RECOV_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_53]

//>> SET_[RECOV_MASK_53]
static inline fapi2::buffer<uint64_t>& SET_RECOV_MASK_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.setBit<RECOV_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RECOV_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_MASK_53]

//>> CLEAR_[RECOV_MASK_53]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_MASK_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return o_data.clearBit<RECOV_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RECOV_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_MASK_53]

//>> GET_[RECOV_MASK_53]
static inline fapi2::buffer<uint64_t>& GET_RECOV_MASK_53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.extractToRight<RECOV_MASK_53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RECOV_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_53]

//>> GET_[RECOV_MASK_53]
static inline bool GET_RECOV_MASK_53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_MASK_RW, RECOV_MASK_WO_CLEAR, RECOV_MASK_WO_OR));
#endif
    return i_data.getBit<RECOV_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RECOV_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_53]

//>> PREP_[TOD_FSM_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_FSM_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_FSM_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_FSM_REG]

//>> GET_[TOD_FSM_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_FSM_REG(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_FSM_REG;
#endif
    return fapi2::getScom(i_target, TOD_FSM_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_FSM_REG]

//>> PUT_[TOD_FSM_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_FSM_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_FSM_REG));
#endif
    return fapi2::putScom(i_target, TOD_FSM_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_FSM_REG]


//>> SET_[TOD_FSM_REG_I_PATH_FSM_STATE]
static inline fapi2::buffer<uint64_t>& SET_TOD_FSM_REG_I_PATH_FSM_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_FSM_REG));
#endif
    return o_data.insertFromRight<TOD_FSM_REG_I_PATH_FSM_STATE,
           TOD_FSM_REG_I_PATH_FSM_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_FSM_REG_I_PATH_FSM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_FSM_REG_I_PATH_FSM_STATE]

//>> SET_[TOD_FSM_REG_I_PATH_FSM_STATE]
static inline fapi2::buffer<uint64_t>& SET_TOD_FSM_REG_I_PATH_FSM_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_FSM_REG));
#endif
    return o_data.insertFromRight<TOD_FSM_REG_I_PATH_FSM_STATE,
           TOD_FSM_REG_I_PATH_FSM_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_FSM_REG_I_PATH_FSM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_FSM_REG_I_PATH_FSM_STATE]

//>> GET_[TOD_FSM_REG_I_PATH_FSM_STATE]
static inline fapi2::buffer<uint64_t>& GET_TOD_FSM_REG_I_PATH_FSM_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_FSM_REG));
#endif
    return i_data.extractToRight<TOD_FSM_REG_I_PATH_FSM_STATE,
           TOD_FSM_REG_I_PATH_FSM_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_FSM_REG_I_PATH_FSM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_FSM_REG_I_PATH_FSM_STATE]

//>> SET_[TOD_FSM_REG_TOD_IS_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_TOD_FSM_REG_TOD_IS_RUNNING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_FSM_REG));
#endif
    return o_data.insertFromRight<TOD_FSM_REG_TOD_IS_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_FSM_REG_TOD_IS_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_FSM_REG_TOD_IS_RUNNING]

//>> SET_[TOD_FSM_REG_TOD_IS_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_TOD_FSM_REG_TOD_IS_RUNNING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_FSM_REG));
#endif
    return o_data.insertFromRight<TOD_FSM_REG_TOD_IS_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_FSM_REG_TOD_IS_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_FSM_REG_TOD_IS_RUNNING]

//>> SET_[TOD_FSM_REG_TOD_IS_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_TOD_FSM_REG_TOD_IS_RUNNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_FSM_REG));
#endif
    return o_data.setBit<TOD_FSM_REG_TOD_IS_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_FSM_REG_TOD_IS_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_FSM_REG_TOD_IS_RUNNING]

//>> CLEAR_[TOD_FSM_REG_TOD_IS_RUNNING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_FSM_REG_TOD_IS_RUNNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_FSM_REG));
#endif
    return o_data.clearBit<TOD_FSM_REG_TOD_IS_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_FSM_REG_TOD_IS_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_FSM_REG_TOD_IS_RUNNING]

//>> GET_[TOD_FSM_REG_TOD_IS_RUNNING]
static inline fapi2::buffer<uint64_t>& GET_TOD_FSM_REG_TOD_IS_RUNNING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_FSM_REG));
#endif
    return i_data.extractToRight<TOD_FSM_REG_TOD_IS_RUNNING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_FSM_REG_TOD_IS_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_FSM_REG_TOD_IS_RUNNING]

//>> GET_[TOD_FSM_REG_TOD_IS_RUNNING]
static inline bool GET_TOD_FSM_REG_TOD_IS_RUNNING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_FSM_REG));
#endif
    return i_data.getBit<TOD_FSM_REG_TOD_IS_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_FSM_REG_TOD_IS_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_FSM_REG_TOD_IS_RUNNING]

//>> SET_[TOD_FSM_REG_REG_0X24_SPARE_05_07]
static inline fapi2::buffer<uint64_t>& SET_TOD_FSM_REG_REG_0X24_SPARE_05_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_FSM_REG));
#endif
    return o_data.insertFromRight<TOD_FSM_REG_REG_0X24_SPARE_05_07,
           TOD_FSM_REG_REG_0X24_SPARE_05_07_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_FSM_REG_REG_0X24_SPARE_05_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_FSM_REG_REG_0X24_SPARE_05_07]

//>> SET_[TOD_FSM_REG_REG_0X24_SPARE_05_07]
static inline fapi2::buffer<uint64_t>& SET_TOD_FSM_REG_REG_0X24_SPARE_05_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_FSM_REG));
#endif
    return o_data.insertFromRight<TOD_FSM_REG_REG_0X24_SPARE_05_07,
           TOD_FSM_REG_REG_0X24_SPARE_05_07_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_FSM_REG_REG_0X24_SPARE_05_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_FSM_REG_REG_0X24_SPARE_05_07]

//>> GET_[TOD_FSM_REG_REG_0X24_SPARE_05_07]
static inline fapi2::buffer<uint64_t>& GET_TOD_FSM_REG_REG_0X24_SPARE_05_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_FSM_REG));
#endif
    return i_data.extractToRight<TOD_FSM_REG_REG_0X24_SPARE_05_07,
           TOD_FSM_REG_REG_0X24_SPARE_05_07_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_FSM_REG_REG_0X24_SPARE_05_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_FSM_REG_REG_0X24_SPARE_05_07]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
