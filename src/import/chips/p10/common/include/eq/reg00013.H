/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/eq/reg00013.H $           */
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

#ifndef __EQ_REG00013_H_
#define __EQ_REG00013_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
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
    FAPI_ERR("0:scom_eq Invalid dial access CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access CTRL_ATOMIC_LOCK_REG_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access CTRL_ATOMIC_LOCK_REG_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access CTRL_ATOMIC_LOCK_REG_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access CTRL_ATOMIC_LOCK_REG_ACTIVITY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access CTRL_ATOMIC_LOCK_REG_ACTIVITY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access CTRL_ATOMIC_LOCK_REG_ACTIVITY chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return fapi2::putScom(i_target, EPS_DBG_DEBUG_TRACE_CONTROL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_DBG_DEBUG_TRACE_CONTROL]


//>> SET_[EPS_DBG_DEBUG_TRACE_CONTROL_START]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_DEBUG_TRACE_CONTROL_START(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return o_data.insertFromRight<EPS_DBG_DEBUG_TRACE_CONTROL_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_DBG_DEBUG_TRACE_CONTROL_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_DEBUG_TRACE_CONTROL_START]

//>> SET_[EPS_DBG_DEBUG_TRACE_CONTROL_START]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_DEBUG_TRACE_CONTROL_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return o_data.insertFromRight<EPS_DBG_DEBUG_TRACE_CONTROL_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_DBG_DEBUG_TRACE_CONTROL_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_DEBUG_TRACE_CONTROL_START]

//>> SET_[EPS_DBG_DEBUG_TRACE_CONTROL_START]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_DEBUG_TRACE_CONTROL_START(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return o_data.setBit<EPS_DBG_DEBUG_TRACE_CONTROL_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_DBG_DEBUG_TRACE_CONTROL_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_DEBUG_TRACE_CONTROL_START]

//>> CLEAR_[EPS_DBG_DEBUG_TRACE_CONTROL_START]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_DEBUG_TRACE_CONTROL_START(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return o_data.clearBit<EPS_DBG_DEBUG_TRACE_CONTROL_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_DBG_DEBUG_TRACE_CONTROL_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_DBG_DEBUG_TRACE_CONTROL_START]

//>> GET_[EPS_DBG_DEBUG_TRACE_CONTROL_START]
static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_DEBUG_TRACE_CONTROL_START(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return i_data.extractToRight<EPS_DBG_DEBUG_TRACE_CONTROL_START,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_DBG_DEBUG_TRACE_CONTROL_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_DEBUG_TRACE_CONTROL_START]

//>> GET_[EPS_DBG_DEBUG_TRACE_CONTROL_START]
static inline bool GET_EPS_DBG_DEBUG_TRACE_CONTROL_START(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return i_data.getBit<EPS_DBG_DEBUG_TRACE_CONTROL_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_DBG_DEBUG_TRACE_CONTROL_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_DEBUG_TRACE_CONTROL_START]

//>> SET_[EPS_DBG_DEBUG_TRACE_CONTROL_STOP]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_DEBUG_TRACE_CONTROL_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return o_data.insertFromRight<EPS_DBG_DEBUG_TRACE_CONTROL_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_DBG_DEBUG_TRACE_CONTROL_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_DEBUG_TRACE_CONTROL_STOP]

//>> SET_[EPS_DBG_DEBUG_TRACE_CONTROL_STOP]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_DEBUG_TRACE_CONTROL_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return o_data.insertFromRight<EPS_DBG_DEBUG_TRACE_CONTROL_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_DBG_DEBUG_TRACE_CONTROL_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_DEBUG_TRACE_CONTROL_STOP]

//>> SET_[EPS_DBG_DEBUG_TRACE_CONTROL_STOP]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_DEBUG_TRACE_CONTROL_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return o_data.setBit<EPS_DBG_DEBUG_TRACE_CONTROL_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_DBG_DEBUG_TRACE_CONTROL_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_DEBUG_TRACE_CONTROL_STOP]

//>> CLEAR_[EPS_DBG_DEBUG_TRACE_CONTROL_STOP]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_DEBUG_TRACE_CONTROL_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return o_data.clearBit<EPS_DBG_DEBUG_TRACE_CONTROL_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_DBG_DEBUG_TRACE_CONTROL_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_DBG_DEBUG_TRACE_CONTROL_STOP]

//>> GET_[EPS_DBG_DEBUG_TRACE_CONTROL_STOP]
static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_DEBUG_TRACE_CONTROL_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return i_data.extractToRight<EPS_DBG_DEBUG_TRACE_CONTROL_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_DBG_DEBUG_TRACE_CONTROL_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_DEBUG_TRACE_CONTROL_STOP]

//>> GET_[EPS_DBG_DEBUG_TRACE_CONTROL_STOP]
static inline bool GET_EPS_DBG_DEBUG_TRACE_CONTROL_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return i_data.getBit<EPS_DBG_DEBUG_TRACE_CONTROL_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_DBG_DEBUG_TRACE_CONTROL_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_DEBUG_TRACE_CONTROL_STOP]

//>> SET_[EPS_DBG_DEBUG_TRACE_CONTROL_RESET]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_DEBUG_TRACE_CONTROL_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return o_data.insertFromRight<EPS_DBG_DEBUG_TRACE_CONTROL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_DBG_DEBUG_TRACE_CONTROL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_DEBUG_TRACE_CONTROL_RESET]

//>> SET_[EPS_DBG_DEBUG_TRACE_CONTROL_RESET]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_DEBUG_TRACE_CONTROL_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return o_data.insertFromRight<EPS_DBG_DEBUG_TRACE_CONTROL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_DBG_DEBUG_TRACE_CONTROL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_DEBUG_TRACE_CONTROL_RESET]

//>> SET_[EPS_DBG_DEBUG_TRACE_CONTROL_RESET]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_DEBUG_TRACE_CONTROL_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return o_data.setBit<EPS_DBG_DEBUG_TRACE_CONTROL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_DBG_DEBUG_TRACE_CONTROL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_DEBUG_TRACE_CONTROL_RESET]

//>> CLEAR_[EPS_DBG_DEBUG_TRACE_CONTROL_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_DEBUG_TRACE_CONTROL_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return o_data.clearBit<EPS_DBG_DEBUG_TRACE_CONTROL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_DBG_DEBUG_TRACE_CONTROL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_DBG_DEBUG_TRACE_CONTROL_RESET]

//>> GET_[EPS_DBG_DEBUG_TRACE_CONTROL_RESET]
static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_DEBUG_TRACE_CONTROL_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return i_data.extractToRight<EPS_DBG_DEBUG_TRACE_CONTROL_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_DBG_DEBUG_TRACE_CONTROL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_DEBUG_TRACE_CONTROL_RESET]

//>> GET_[EPS_DBG_DEBUG_TRACE_CONTROL_RESET]
static inline bool GET_EPS_DBG_DEBUG_TRACE_CONTROL_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_DEBUG_TRACE_CONTROL));
#endif
    return i_data.getBit<EPS_DBG_DEBUG_TRACE_CONTROL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_DBG_DEBUG_TRACE_CONTROL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_DEBUG_TRACE_CONTROL_RESET]

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
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT1_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT1_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT1_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT1_SEQ_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT1_SEQ_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT1_SEQ_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT1_SEQ_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT1_SEQ_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT1_SEQ_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT1_SEQ_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT1_SEQ_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT1_SEQ_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT1_SEQ_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT1_SEQ_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT1_SEQ_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT1_SEQ_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT1_SEQ_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT1_SEQ_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT1_SEQ_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT1_SEQ_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT1_SEQ_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT1_SEQ_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT1_SEQ_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT1_SEQ_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT1_SEQ_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT1_SEQ_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT1_SEQ_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT1_SEQ_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT1_SEQ_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT1_SEQ_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT1_SEQ_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT1_SEQ_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT1_SEQ_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT1_SEQ_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT1_SEQ_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT1_SEQ_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT1_SEQ_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT1_SEQ_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT1_SEQ_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT1_SEQ_12]

//>> PREP_[QME_EIMR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_EIMR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_EIMR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_EIMR_RW]

//>> GET_[QME_EIMR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_EIMR_RW(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_EIMR_RW;
#endif
    return fapi2::getScom(i_target, QME_EIMR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_EIMR_RW]

//>> PUT_[QME_EIMR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_EIMR_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_EIMR_RW, QME_EIMR_WO_CLEAR, QME_EIMR_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_EIMR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_EIMR_RW]

//>> PREP_[QME_EIMR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_EIMR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_EIMR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_EIMR_WO_CLEAR]

//>> GET_[QME_EIMR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_EIMR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_EIMR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, QME_EIMR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_EIMR_WO_CLEAR]

//>> PUT_[QME_EIMR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_EIMR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_EIMR_RW, QME_EIMR_WO_CLEAR, QME_EIMR_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_EIMR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_EIMR_WO_CLEAR]

//>> PREP_[QME_EIMR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_EIMR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_EIMR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_EIMR_WO_OR]

//>> GET_[QME_EIMR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_EIMR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_EIMR_WO_OR;
#endif
    return fapi2::getScom(i_target, QME_EIMR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_EIMR_WO_OR]

//>> PUT_[QME_EIMR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_EIMR_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_EIMR_RW, QME_EIMR_WO_CLEAR, QME_EIMR_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_EIMR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_EIMR_WO_OR]


//>> SET_[QME_EIMR_INTERRUPT_MASK]
static inline fapi2::buffer<uint64_t>& SET_QME_EIMR_INTERRUPT_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EIMR_RW, QME_EIMR_WO_CLEAR, QME_EIMR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EIMR_INTERRUPT_MASK,
           QME_EIMR_INTERRUPT_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EIMR_INTERRUPT_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EIMR_INTERRUPT_MASK]

//>> SET_[QME_EIMR_INTERRUPT_MASK]
static inline fapi2::buffer<uint64_t>& SET_QME_EIMR_INTERRUPT_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EIMR_RW, QME_EIMR_WO_CLEAR, QME_EIMR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EIMR_INTERRUPT_MASK,
           QME_EIMR_INTERRUPT_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EIMR_INTERRUPT_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EIMR_INTERRUPT_MASK]

//>> GET_[QME_EIMR_INTERRUPT_MASK]
static inline fapi2::buffer<uint64_t>& GET_QME_EIMR_INTERRUPT_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EIMR_RW, QME_EIMR_WO_CLEAR, QME_EIMR_WO_OR));
#endif
    return i_data.extractToRight<QME_EIMR_INTERRUPT_MASK,
           QME_EIMR_INTERRUPT_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EIMR_INTERRUPT_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EIMR_INTERRUPT_MASK]

//>> PREP_[QME_PIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_PIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_PIG]

//>> GET_[QME_PIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_PIG(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PIG;
#endif
    return fapi2::getScom(i_target, QME_PIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_PIG]

//>> PUT_[QME_PIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_PIG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return fapi2::putScom(i_target, QME_PIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_PIG]


//>> SET_[QME_PIG_REQ_INTR_TYPE]
static inline fapi2::buffer<uint64_t>& SET_QME_PIG_REQ_INTR_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return o_data.insertFromRight<QME_PIG_REQ_INTR_TYPE,
           QME_PIG_REQ_INTR_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PIG_REQ_INTR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PIG_REQ_INTR_TYPE]

//>> SET_[QME_PIG_REQ_INTR_TYPE]
static inline fapi2::buffer<uint64_t>& SET_QME_PIG_REQ_INTR_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return o_data.insertFromRight<QME_PIG_REQ_INTR_TYPE,
           QME_PIG_REQ_INTR_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PIG_REQ_INTR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PIG_REQ_INTR_TYPE]

//>> GET_[QME_PIG_REQ_INTR_TYPE]
static inline fapi2::buffer<uint64_t>& GET_QME_PIG_REQ_INTR_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return i_data.extractToRight<QME_PIG_REQ_INTR_TYPE,
           QME_PIG_REQ_INTR_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PIG_REQ_INTR_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PIG_REQ_INTR_TYPE]

//>> SET_[QME_PIG_REQ_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& SET_QME_PIG_REQ_INTR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return o_data.insertFromRight<QME_PIG_REQ_INTR_PAYLOAD,
           QME_PIG_REQ_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PIG_REQ_INTR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PIG_REQ_INTR_PAYLOAD]

//>> SET_[QME_PIG_REQ_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& SET_QME_PIG_REQ_INTR_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return o_data.insertFromRight<QME_PIG_REQ_INTR_PAYLOAD,
           QME_PIG_REQ_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PIG_REQ_INTR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PIG_REQ_INTR_PAYLOAD]

//>> GET_[QME_PIG_REQ_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& GET_QME_PIG_REQ_INTR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return i_data.extractToRight<QME_PIG_REQ_INTR_PAYLOAD,
           QME_PIG_REQ_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PIG_REQ_INTR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PIG_REQ_INTR_PAYLOAD]

//>> SET_[QME_PIG_PENDING_SOURCE]
static inline fapi2::buffer<uint64_t>& SET_QME_PIG_PENDING_SOURCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return o_data.insertFromRight<QME_PIG_PENDING_SOURCE,
           QME_PIG_PENDING_SOURCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PIG_PENDING_SOURCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PIG_PENDING_SOURCE]

//>> SET_[QME_PIG_PENDING_SOURCE]
static inline fapi2::buffer<uint64_t>& SET_QME_PIG_PENDING_SOURCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return o_data.insertFromRight<QME_PIG_PENDING_SOURCE,
           QME_PIG_PENDING_SOURCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PIG_PENDING_SOURCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PIG_PENDING_SOURCE]

//>> GET_[QME_PIG_PENDING_SOURCE]
static inline fapi2::buffer<uint64_t>& GET_QME_PIG_PENDING_SOURCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return i_data.extractToRight<QME_PIG_PENDING_SOURCE,
           QME_PIG_PENDING_SOURCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PIG_PENDING_SOURCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PIG_PENDING_SOURCE]

//>> SET_[QME_PIG_INTR_GRANTED]
static inline fapi2::buffer<uint64_t>& SET_QME_PIG_INTR_GRANTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return o_data.insertFromRight<QME_PIG_INTR_GRANTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PIG_INTR_GRANTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PIG_INTR_GRANTED]

//>> SET_[QME_PIG_INTR_GRANTED]
static inline fapi2::buffer<uint64_t>& SET_QME_PIG_INTR_GRANTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return o_data.insertFromRight<QME_PIG_INTR_GRANTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PIG_INTR_GRANTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PIG_INTR_GRANTED]

//>> SET_[QME_PIG_INTR_GRANTED]
static inline fapi2::buffer<uint64_t>& SET_QME_PIG_INTR_GRANTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return o_data.setBit<QME_PIG_INTR_GRANTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PIG_INTR_GRANTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PIG_INTR_GRANTED]

//>> CLEAR_[QME_PIG_INTR_GRANTED]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PIG_INTR_GRANTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return o_data.clearBit<QME_PIG_INTR_GRANTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PIG_INTR_GRANTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PIG_INTR_GRANTED]

//>> GET_[QME_PIG_INTR_GRANTED]
static inline fapi2::buffer<uint64_t>& GET_QME_PIG_INTR_GRANTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return i_data.extractToRight<QME_PIG_INTR_GRANTED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PIG_INTR_GRANTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PIG_INTR_GRANTED]

//>> GET_[QME_PIG_INTR_GRANTED]
static inline bool GET_QME_PIG_INTR_GRANTED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return i_data.getBit<QME_PIG_INTR_GRANTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PIG_INTR_GRANTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PIG_INTR_GRANTED]

//>> SET_[QME_PIG_GRANTED_SOURCE]
static inline fapi2::buffer<uint64_t>& SET_QME_PIG_GRANTED_SOURCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return o_data.insertFromRight<QME_PIG_GRANTED_SOURCE,
           QME_PIG_GRANTED_SOURCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PIG_GRANTED_SOURCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PIG_GRANTED_SOURCE]

//>> SET_[QME_PIG_GRANTED_SOURCE]
static inline fapi2::buffer<uint64_t>& SET_QME_PIG_GRANTED_SOURCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return o_data.insertFromRight<QME_PIG_GRANTED_SOURCE,
           QME_PIG_GRANTED_SOURCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PIG_GRANTED_SOURCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PIG_GRANTED_SOURCE]

//>> GET_[QME_PIG_GRANTED_SOURCE]
static inline fapi2::buffer<uint64_t>& GET_QME_PIG_GRANTED_SOURCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return i_data.extractToRight<QME_PIG_GRANTED_SOURCE,
           QME_PIG_GRANTED_SOURCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PIG_GRANTED_SOURCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PIG_GRANTED_SOURCE]

//>> SET_[QME_PIG_QUAD_ID]
static inline fapi2::buffer<uint64_t>& SET_QME_PIG_QUAD_ID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return o_data.insertFromRight<QME_PIG_QUAD_ID,
           QME_PIG_QUAD_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PIG_QUAD_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PIG_QUAD_ID]

//>> SET_[QME_PIG_QUAD_ID]
static inline fapi2::buffer<uint64_t>& SET_QME_PIG_QUAD_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return o_data.insertFromRight<QME_PIG_QUAD_ID,
           QME_PIG_QUAD_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PIG_QUAD_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PIG_QUAD_ID]

//>> GET_[QME_PIG_QUAD_ID]
static inline fapi2::buffer<uint64_t>& GET_QME_PIG_QUAD_ID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return i_data.extractToRight<QME_PIG_QUAD_ID,
           QME_PIG_QUAD_ID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PIG_QUAD_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PIG_QUAD_ID]

//>> SET_[QME_PIG_GRANTED_PACKET]
static inline fapi2::buffer<uint64_t>& SET_QME_PIG_GRANTED_PACKET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return o_data.insertFromRight<QME_PIG_GRANTED_PACKET,
           QME_PIG_GRANTED_PACKET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PIG_GRANTED_PACKET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PIG_GRANTED_PACKET]

//>> SET_[QME_PIG_GRANTED_PACKET]
static inline fapi2::buffer<uint64_t>& SET_QME_PIG_GRANTED_PACKET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return o_data.insertFromRight<QME_PIG_GRANTED_PACKET,
           QME_PIG_GRANTED_PACKET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PIG_GRANTED_PACKET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PIG_GRANTED_PACKET]

//>> GET_[QME_PIG_GRANTED_PACKET]
static inline fapi2::buffer<uint64_t>& GET_QME_PIG_GRANTED_PACKET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PIG));
#endif
    return i_data.extractToRight<QME_PIG_GRANTED_PACKET,
           QME_PIG_GRANTED_PACKET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PIG_GRANTED_PACKET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PIG_GRANTED_PACKET]

//>> PREP_[QME_QSCR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_QSCR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_QSCR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_QSCR_RW]

//>> GET_[QME_QSCR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_QSCR_RW(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_QSCR_RW;
#endif
    return fapi2::getScom(i_target, QME_QSCR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_QSCR_RW]

//>> PUT_[QME_QSCR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_QSCR_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_QSCR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_QSCR_RW]

//>> PREP_[QME_QSCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_QSCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_QSCR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_QSCR_WO_CLEAR]

//>> GET_[QME_QSCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_QSCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_QSCR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, QME_QSCR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_QSCR_WO_CLEAR]

//>> PUT_[QME_QSCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_QSCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_QSCR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_QSCR_WO_CLEAR]

//>> PREP_[QME_QSCR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_QSCR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_QSCR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_QSCR_WO_OR]

//>> GET_[QME_QSCR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_QSCR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_QSCR_WO_OR;
#endif
    return fapi2::getScom(i_target, QME_QSCR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_QSCR_WO_OR]

//>> PUT_[QME_QSCR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_QSCR_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_QSCR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_QSCR_WO_OR]


//>> SET_[QME_QSCR_SRAM_ACCESS_MODE]
static inline fapi2::buffer<uint64_t>& SET_QME_QSCR_SRAM_ACCESS_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_QSCR_SRAM_ACCESS_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_QSCR_SRAM_ACCESS_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSCR_SRAM_ACCESS_MODE]

//>> SET_[QME_QSCR_SRAM_ACCESS_MODE]
static inline fapi2::buffer<uint64_t>& SET_QME_QSCR_SRAM_ACCESS_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_QSCR_SRAM_ACCESS_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_QSCR_SRAM_ACCESS_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSCR_SRAM_ACCESS_MODE]

//>> SET_[QME_QSCR_SRAM_ACCESS_MODE]
static inline fapi2::buffer<uint64_t>& SET_QME_QSCR_SRAM_ACCESS_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.setBit<QME_QSCR_SRAM_ACCESS_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_QSCR_SRAM_ACCESS_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSCR_SRAM_ACCESS_MODE]

//>> CLEAR_[QME_QSCR_SRAM_ACCESS_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_QSCR_SRAM_ACCESS_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.clearBit<QME_QSCR_SRAM_ACCESS_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_QSCR_SRAM_ACCESS_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_QSCR_SRAM_ACCESS_MODE]

//>> GET_[QME_QSCR_SRAM_ACCESS_MODE]
static inline fapi2::buffer<uint64_t>& GET_QME_QSCR_SRAM_ACCESS_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return i_data.extractToRight<QME_QSCR_SRAM_ACCESS_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_QSCR_SRAM_ACCESS_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QSCR_SRAM_ACCESS_MODE]

//>> GET_[QME_QSCR_SRAM_ACCESS_MODE]
static inline bool GET_QME_QSCR_SRAM_ACCESS_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return i_data.getBit<QME_QSCR_SRAM_ACCESS_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_QSCR_SRAM_ACCESS_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QSCR_SRAM_ACCESS_MODE]

//>> SET_[QME_QSCR_SRAM_SCRUB_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_QSCR_SRAM_SCRUB_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_QSCR_SRAM_SCRUB_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_QSCR_SRAM_SCRUB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSCR_SRAM_SCRUB_ENABLE]

//>> SET_[QME_QSCR_SRAM_SCRUB_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_QSCR_SRAM_SCRUB_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_QSCR_SRAM_SCRUB_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_QSCR_SRAM_SCRUB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSCR_SRAM_SCRUB_ENABLE]

//>> SET_[QME_QSCR_SRAM_SCRUB_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_QSCR_SRAM_SCRUB_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.setBit<QME_QSCR_SRAM_SCRUB_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_QSCR_SRAM_SCRUB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSCR_SRAM_SCRUB_ENABLE]

//>> CLEAR_[QME_QSCR_SRAM_SCRUB_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_QSCR_SRAM_SCRUB_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.clearBit<QME_QSCR_SRAM_SCRUB_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_QSCR_SRAM_SCRUB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_QSCR_SRAM_SCRUB_ENABLE]

//>> GET_[QME_QSCR_SRAM_SCRUB_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_QSCR_SRAM_SCRUB_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return i_data.extractToRight<QME_QSCR_SRAM_SCRUB_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_QSCR_SRAM_SCRUB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QSCR_SRAM_SCRUB_ENABLE]

//>> GET_[QME_QSCR_SRAM_SCRUB_ENABLE]
static inline bool GET_QME_QSCR_SRAM_SCRUB_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return i_data.getBit<QME_QSCR_SRAM_SCRUB_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_QSCR_SRAM_SCRUB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QSCR_SRAM_SCRUB_ENABLE]

//>> SET_[QME_QSCR_ECC_CORRECT_DIS]
static inline fapi2::buffer<uint64_t>& SET_QME_QSCR_ECC_CORRECT_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_QSCR_ECC_CORRECT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_QSCR_ECC_CORRECT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSCR_ECC_CORRECT_DIS]

//>> SET_[QME_QSCR_ECC_CORRECT_DIS]
static inline fapi2::buffer<uint64_t>& SET_QME_QSCR_ECC_CORRECT_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_QSCR_ECC_CORRECT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_QSCR_ECC_CORRECT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSCR_ECC_CORRECT_DIS]

//>> SET_[QME_QSCR_ECC_CORRECT_DIS]
static inline fapi2::buffer<uint64_t>& SET_QME_QSCR_ECC_CORRECT_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.setBit<QME_QSCR_ECC_CORRECT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_QSCR_ECC_CORRECT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSCR_ECC_CORRECT_DIS]

//>> CLEAR_[QME_QSCR_ECC_CORRECT_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_QSCR_ECC_CORRECT_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.clearBit<QME_QSCR_ECC_CORRECT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_QSCR_ECC_CORRECT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_QSCR_ECC_CORRECT_DIS]

//>> GET_[QME_QSCR_ECC_CORRECT_DIS]
static inline fapi2::buffer<uint64_t>& GET_QME_QSCR_ECC_CORRECT_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return i_data.extractToRight<QME_QSCR_ECC_CORRECT_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_QSCR_ECC_CORRECT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QSCR_ECC_CORRECT_DIS]

//>> GET_[QME_QSCR_ECC_CORRECT_DIS]
static inline bool GET_QME_QSCR_ECC_CORRECT_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return i_data.getBit<QME_QSCR_ECC_CORRECT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_QSCR_ECC_CORRECT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QSCR_ECC_CORRECT_DIS]

//>> SET_[QME_QSCR_ECC_DETECT_DIS]
static inline fapi2::buffer<uint64_t>& SET_QME_QSCR_ECC_DETECT_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_QSCR_ECC_DETECT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_QSCR_ECC_DETECT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSCR_ECC_DETECT_DIS]

//>> SET_[QME_QSCR_ECC_DETECT_DIS]
static inline fapi2::buffer<uint64_t>& SET_QME_QSCR_ECC_DETECT_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_QSCR_ECC_DETECT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_QSCR_ECC_DETECT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSCR_ECC_DETECT_DIS]

//>> SET_[QME_QSCR_ECC_DETECT_DIS]
static inline fapi2::buffer<uint64_t>& SET_QME_QSCR_ECC_DETECT_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.setBit<QME_QSCR_ECC_DETECT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_QSCR_ECC_DETECT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSCR_ECC_DETECT_DIS]

//>> CLEAR_[QME_QSCR_ECC_DETECT_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_QSCR_ECC_DETECT_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.clearBit<QME_QSCR_ECC_DETECT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_QSCR_ECC_DETECT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_QSCR_ECC_DETECT_DIS]

//>> GET_[QME_QSCR_ECC_DETECT_DIS]
static inline fapi2::buffer<uint64_t>& GET_QME_QSCR_ECC_DETECT_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return i_data.extractToRight<QME_QSCR_ECC_DETECT_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_QSCR_ECC_DETECT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QSCR_ECC_DETECT_DIS]

//>> GET_[QME_QSCR_ECC_DETECT_DIS]
static inline bool GET_QME_QSCR_ECC_DETECT_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return i_data.getBit<QME_QSCR_ECC_DETECT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_QSCR_ECC_DETECT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QSCR_ECC_DETECT_DIS]

//>> SET_[QME_QSCR_ECC_INJECT_TYPE]
static inline fapi2::buffer<uint64_t>& SET_QME_QSCR_ECC_INJECT_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_QSCR_ECC_INJECT_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_QSCR_ECC_INJECT_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSCR_ECC_INJECT_TYPE]

//>> SET_[QME_QSCR_ECC_INJECT_TYPE]
static inline fapi2::buffer<uint64_t>& SET_QME_QSCR_ECC_INJECT_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_QSCR_ECC_INJECT_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_QSCR_ECC_INJECT_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSCR_ECC_INJECT_TYPE]

//>> SET_[QME_QSCR_ECC_INJECT_TYPE]
static inline fapi2::buffer<uint64_t>& SET_QME_QSCR_ECC_INJECT_TYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.setBit<QME_QSCR_ECC_INJECT_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_QSCR_ECC_INJECT_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSCR_ECC_INJECT_TYPE]

//>> CLEAR_[QME_QSCR_ECC_INJECT_TYPE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_QSCR_ECC_INJECT_TYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.clearBit<QME_QSCR_ECC_INJECT_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_QSCR_ECC_INJECT_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_QSCR_ECC_INJECT_TYPE]

//>> GET_[QME_QSCR_ECC_INJECT_TYPE]
static inline fapi2::buffer<uint64_t>& GET_QME_QSCR_ECC_INJECT_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return i_data.extractToRight<QME_QSCR_ECC_INJECT_TYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_QSCR_ECC_INJECT_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QSCR_ECC_INJECT_TYPE]

//>> GET_[QME_QSCR_ECC_INJECT_TYPE]
static inline bool GET_QME_QSCR_ECC_INJECT_TYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return i_data.getBit<QME_QSCR_ECC_INJECT_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_QSCR_ECC_INJECT_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QSCR_ECC_INJECT_TYPE]

//>> SET_[QME_QSCR_ECC_INJECT_ERR]
static inline fapi2::buffer<uint64_t>& SET_QME_QSCR_ECC_INJECT_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_QSCR_ECC_INJECT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_QSCR_ECC_INJECT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSCR_ECC_INJECT_ERR]

//>> SET_[QME_QSCR_ECC_INJECT_ERR]
static inline fapi2::buffer<uint64_t>& SET_QME_QSCR_ECC_INJECT_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_QSCR_ECC_INJECT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_QSCR_ECC_INJECT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSCR_ECC_INJECT_ERR]

//>> SET_[QME_QSCR_ECC_INJECT_ERR]
static inline fapi2::buffer<uint64_t>& SET_QME_QSCR_ECC_INJECT_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.setBit<QME_QSCR_ECC_INJECT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_QSCR_ECC_INJECT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSCR_ECC_INJECT_ERR]

//>> CLEAR_[QME_QSCR_ECC_INJECT_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_QSCR_ECC_INJECT_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.clearBit<QME_QSCR_ECC_INJECT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_QSCR_ECC_INJECT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_QSCR_ECC_INJECT_ERR]

//>> GET_[QME_QSCR_ECC_INJECT_ERR]
static inline fapi2::buffer<uint64_t>& GET_QME_QSCR_ECC_INJECT_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return i_data.extractToRight<QME_QSCR_ECC_INJECT_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_QSCR_ECC_INJECT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QSCR_ECC_INJECT_ERR]

//>> GET_[QME_QSCR_ECC_INJECT_ERR]
static inline bool GET_QME_QSCR_ECC_INJECT_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return i_data.getBit<QME_QSCR_ECC_INJECT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_QSCR_ECC_INJECT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QSCR_ECC_INJECT_ERR]

//>> SET_[QME_QSCR_SPARE_6_7]
static inline fapi2::buffer<uint64_t>& SET_QME_QSCR_SPARE_6_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_QSCR_SPARE_6_7,
           QME_QSCR_SPARE_6_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_QSCR_SPARE_6_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSCR_SPARE_6_7]

//>> SET_[QME_QSCR_SPARE_6_7]
static inline fapi2::buffer<uint64_t>& SET_QME_QSCR_SPARE_6_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_QSCR_SPARE_6_7,
           QME_QSCR_SPARE_6_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_QSCR_SPARE_6_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSCR_SPARE_6_7]

//>> GET_[QME_QSCR_SPARE_6_7]
static inline fapi2::buffer<uint64_t>& GET_QME_QSCR_SPARE_6_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return i_data.extractToRight<QME_QSCR_SPARE_6_7,
           QME_QSCR_SPARE_6_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_QSCR_SPARE_6_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QSCR_SPARE_6_7]

//>> SET_[QME_QSCR_DTCBASE]
static inline fapi2::buffer<uint64_t>& SET_QME_QSCR_DTCBASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_QSCR_DTCBASE,
           QME_QSCR_DTCBASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_QSCR_DTCBASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSCR_DTCBASE]

//>> SET_[QME_QSCR_DTCBASE]
static inline fapi2::buffer<uint64_t>& SET_QME_QSCR_DTCBASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_QSCR_DTCBASE,
           QME_QSCR_DTCBASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_QSCR_DTCBASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSCR_DTCBASE]

//>> GET_[QME_QSCR_DTCBASE]
static inline fapi2::buffer<uint64_t>& GET_QME_QSCR_DTCBASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return i_data.extractToRight<QME_QSCR_DTCBASE,
           QME_QSCR_DTCBASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_QSCR_DTCBASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QSCR_DTCBASE]

//>> SET_[QME_QSCR_SRAM_SCRUB_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_QSCR_SRAM_SCRUB_INDEX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_QSCR_SRAM_SCRUB_INDEX,
           QME_QSCR_SRAM_SCRUB_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_QSCR_SRAM_SCRUB_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSCR_SRAM_SCRUB_INDEX]

//>> SET_[QME_QSCR_SRAM_SCRUB_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_QSCR_SRAM_SCRUB_INDEX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_QSCR_SRAM_SCRUB_INDEX,
           QME_QSCR_SRAM_SCRUB_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_QSCR_SRAM_SCRUB_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QSCR_SRAM_SCRUB_INDEX]

//>> GET_[QME_QSCR_SRAM_SCRUB_INDEX]
static inline fapi2::buffer<uint64_t>& GET_QME_QSCR_SRAM_SCRUB_INDEX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_QSCR_RW, QME_QSCR_WO_CLEAR, QME_QSCR_WO_OR));
#endif
    return i_data.extractToRight<QME_QSCR_SRAM_SCRUB_INDEX,
           QME_QSCR_SRAM_SCRUB_INDEX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_QSCR_SRAM_SCRUB_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QSCR_SRAM_SCRUB_INDEX]

//>> PREP_[QME_RCMR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_RCMR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_RCMR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_RCMR]

//>> GET_[QME_RCMR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_RCMR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_RCMR;
#endif
    return fapi2::getScom(i_target, QME_RCMR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_RCMR]

//>> PUT_[QME_RCMR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_RCMR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_RCMR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_RCMR]

//>> PREP_[QME_RCMR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_RCMR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_RCMR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_RCMR_WO_CLEAR]

//>> GET_[QME_RCMR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_RCMR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_RCMR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, QME_RCMR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_RCMR_WO_CLEAR]

//>> PUT_[QME_RCMR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_RCMR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_RCMR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_RCMR_WO_CLEAR]

//>> PREP_[QME_RCMR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_RCMR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_RCMR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_RCMR_WO_OR]

//>> GET_[QME_RCMR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_RCMR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_RCMR_WO_OR;
#endif
    return fapi2::getScom(i_target, QME_RCMR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_RCMR_WO_OR]

//>> PUT_[QME_RCMR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_RCMR_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_RCMR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_RCMR_WO_OR]


//>> SET_[QME_RCMR_STEP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_RCMR_STEP_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCMR_STEP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCMR_STEP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCMR_STEP_ENABLE]

//>> SET_[QME_RCMR_STEP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_RCMR_STEP_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCMR_STEP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCMR_STEP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCMR_STEP_ENABLE]

//>> SET_[QME_RCMR_STEP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_RCMR_STEP_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.setBit<QME_RCMR_STEP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_RCMR_STEP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCMR_STEP_ENABLE]

//>> CLEAR_[QME_RCMR_STEP_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_RCMR_STEP_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.clearBit<QME_RCMR_STEP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_RCMR_STEP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_RCMR_STEP_ENABLE]

//>> GET_[QME_RCMR_STEP_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_RCMR_STEP_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return i_data.extractToRight<QME_RCMR_STEP_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCMR_STEP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCMR_STEP_ENABLE]

//>> GET_[QME_RCMR_STEP_ENABLE]
static inline bool GET_QME_RCMR_STEP_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return i_data.getBit<QME_RCMR_STEP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_RCMR_STEP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCMR_STEP_ENABLE]

//>> SET_[QME_RCMR_AUTO_ACK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_RCMR_AUTO_ACK_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCMR_AUTO_ACK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCMR_AUTO_ACK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCMR_AUTO_ACK_ENABLE]

//>> SET_[QME_RCMR_AUTO_ACK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_RCMR_AUTO_ACK_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCMR_AUTO_ACK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCMR_AUTO_ACK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCMR_AUTO_ACK_ENABLE]

//>> SET_[QME_RCMR_AUTO_ACK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_RCMR_AUTO_ACK_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.setBit<QME_RCMR_AUTO_ACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_RCMR_AUTO_ACK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCMR_AUTO_ACK_ENABLE]

//>> CLEAR_[QME_RCMR_AUTO_ACK_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_RCMR_AUTO_ACK_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.clearBit<QME_RCMR_AUTO_ACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_RCMR_AUTO_ACK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_RCMR_AUTO_ACK_ENABLE]

//>> GET_[QME_RCMR_AUTO_ACK_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_RCMR_AUTO_ACK_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return i_data.extractToRight<QME_RCMR_AUTO_ACK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCMR_AUTO_ACK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCMR_AUTO_ACK_ENABLE]

//>> GET_[QME_RCMR_AUTO_ACK_ENABLE]
static inline bool GET_QME_RCMR_AUTO_ACK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return i_data.getBit<QME_RCMR_AUTO_ACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_RCMR_AUTO_ACK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCMR_AUTO_ACK_ENABLE]

//>> SET_[QME_RCMR_AUTO_TARGET_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_RCMR_AUTO_TARGET_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCMR_AUTO_TARGET_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCMR_AUTO_TARGET_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCMR_AUTO_TARGET_DISABLE]

//>> SET_[QME_RCMR_AUTO_TARGET_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_RCMR_AUTO_TARGET_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCMR_AUTO_TARGET_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCMR_AUTO_TARGET_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCMR_AUTO_TARGET_DISABLE]

//>> SET_[QME_RCMR_AUTO_TARGET_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_RCMR_AUTO_TARGET_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.setBit<QME_RCMR_AUTO_TARGET_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_RCMR_AUTO_TARGET_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCMR_AUTO_TARGET_DISABLE]

//>> CLEAR_[QME_RCMR_AUTO_TARGET_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_RCMR_AUTO_TARGET_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.clearBit<QME_RCMR_AUTO_TARGET_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_RCMR_AUTO_TARGET_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_RCMR_AUTO_TARGET_DISABLE]

//>> GET_[QME_RCMR_AUTO_TARGET_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_RCMR_AUTO_TARGET_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return i_data.extractToRight<QME_RCMR_AUTO_TARGET_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCMR_AUTO_TARGET_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCMR_AUTO_TARGET_DISABLE]

//>> GET_[QME_RCMR_AUTO_TARGET_DISABLE]
static inline bool GET_QME_RCMR_AUTO_TARGET_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return i_data.getBit<QME_RCMR_AUTO_TARGET_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_RCMR_AUTO_TARGET_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCMR_AUTO_TARGET_DISABLE]

//>> SET_[QME_RCMR_AUTO_DONE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_RCMR_AUTO_DONE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCMR_AUTO_DONE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCMR_AUTO_DONE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCMR_AUTO_DONE_DISABLE]

//>> SET_[QME_RCMR_AUTO_DONE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_RCMR_AUTO_DONE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCMR_AUTO_DONE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCMR_AUTO_DONE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCMR_AUTO_DONE_DISABLE]

//>> SET_[QME_RCMR_AUTO_DONE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_RCMR_AUTO_DONE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.setBit<QME_RCMR_AUTO_DONE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_RCMR_AUTO_DONE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCMR_AUTO_DONE_DISABLE]

//>> CLEAR_[QME_RCMR_AUTO_DONE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_RCMR_AUTO_DONE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.clearBit<QME_RCMR_AUTO_DONE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_RCMR_AUTO_DONE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_RCMR_AUTO_DONE_DISABLE]

//>> GET_[QME_RCMR_AUTO_DONE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_RCMR_AUTO_DONE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return i_data.extractToRight<QME_RCMR_AUTO_DONE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCMR_AUTO_DONE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCMR_AUTO_DONE_DISABLE]

//>> GET_[QME_RCMR_AUTO_DONE_DISABLE]
static inline bool GET_QME_RCMR_AUTO_DONE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return i_data.getBit<QME_RCMR_AUTO_DONE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_RCMR_AUTO_DONE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCMR_AUTO_DONE_DISABLE]

//>> SET_[QME_RCMR_STEP_DELAY]
static inline fapi2::buffer<uint64_t>& SET_QME_RCMR_STEP_DELAY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCMR_STEP_DELAY,
           QME_RCMR_STEP_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCMR_STEP_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCMR_STEP_DELAY]

//>> SET_[QME_RCMR_STEP_DELAY]
static inline fapi2::buffer<uint64_t>& SET_QME_RCMR_STEP_DELAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCMR_STEP_DELAY,
           QME_RCMR_STEP_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCMR_STEP_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCMR_STEP_DELAY]

//>> GET_[QME_RCMR_STEP_DELAY]
static inline fapi2::buffer<uint64_t>& GET_QME_RCMR_STEP_DELAY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return i_data.extractToRight<QME_RCMR_STEP_DELAY,
           QME_RCMR_STEP_DELAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCMR_STEP_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCMR_STEP_DELAY]

//>> SET_[QME_RCMR_CORE0_CONTROL_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_RCMR_CORE0_CONTROL_INDEX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCMR_CORE0_CONTROL_INDEX,
           QME_RCMR_CORE0_CONTROL_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCMR_CORE0_CONTROL_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCMR_CORE0_CONTROL_INDEX]

//>> SET_[QME_RCMR_CORE0_CONTROL_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_RCMR_CORE0_CONTROL_INDEX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCMR_CORE0_CONTROL_INDEX,
           QME_RCMR_CORE0_CONTROL_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCMR_CORE0_CONTROL_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCMR_CORE0_CONTROL_INDEX]

//>> GET_[QME_RCMR_CORE0_CONTROL_INDEX]
static inline fapi2::buffer<uint64_t>& GET_QME_RCMR_CORE0_CONTROL_INDEX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return i_data.extractToRight<QME_RCMR_CORE0_CONTROL_INDEX,
           QME_RCMR_CORE0_CONTROL_INDEX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCMR_CORE0_CONTROL_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCMR_CORE0_CONTROL_INDEX]

//>> SET_[QME_RCMR_CORE1_CONTROL_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_RCMR_CORE1_CONTROL_INDEX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCMR_CORE1_CONTROL_INDEX,
           QME_RCMR_CORE1_CONTROL_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCMR_CORE1_CONTROL_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCMR_CORE1_CONTROL_INDEX]

//>> SET_[QME_RCMR_CORE1_CONTROL_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_RCMR_CORE1_CONTROL_INDEX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCMR_CORE1_CONTROL_INDEX,
           QME_RCMR_CORE1_CONTROL_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCMR_CORE1_CONTROL_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCMR_CORE1_CONTROL_INDEX]

//>> GET_[QME_RCMR_CORE1_CONTROL_INDEX]
static inline fapi2::buffer<uint64_t>& GET_QME_RCMR_CORE1_CONTROL_INDEX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return i_data.extractToRight<QME_RCMR_CORE1_CONTROL_INDEX,
           QME_RCMR_CORE1_CONTROL_INDEX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCMR_CORE1_CONTROL_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCMR_CORE1_CONTROL_INDEX]

//>> SET_[QME_RCMR_CORE2_CONTROL_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_RCMR_CORE2_CONTROL_INDEX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCMR_CORE2_CONTROL_INDEX,
           QME_RCMR_CORE2_CONTROL_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCMR_CORE2_CONTROL_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCMR_CORE2_CONTROL_INDEX]

//>> SET_[QME_RCMR_CORE2_CONTROL_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_RCMR_CORE2_CONTROL_INDEX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCMR_CORE2_CONTROL_INDEX,
           QME_RCMR_CORE2_CONTROL_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCMR_CORE2_CONTROL_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCMR_CORE2_CONTROL_INDEX]

//>> GET_[QME_RCMR_CORE2_CONTROL_INDEX]
static inline fapi2::buffer<uint64_t>& GET_QME_RCMR_CORE2_CONTROL_INDEX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return i_data.extractToRight<QME_RCMR_CORE2_CONTROL_INDEX,
           QME_RCMR_CORE2_CONTROL_INDEX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCMR_CORE2_CONTROL_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCMR_CORE2_CONTROL_INDEX]

//>> SET_[QME_RCMR_CORE3_CONTROL_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_RCMR_CORE3_CONTROL_INDEX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCMR_CORE3_CONTROL_INDEX,
           QME_RCMR_CORE3_CONTROL_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCMR_CORE3_CONTROL_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCMR_CORE3_CONTROL_INDEX]

//>> SET_[QME_RCMR_CORE3_CONTROL_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_RCMR_CORE3_CONTROL_INDEX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCMR_CORE3_CONTROL_INDEX,
           QME_RCMR_CORE3_CONTROL_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCMR_CORE3_CONTROL_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCMR_CORE3_CONTROL_INDEX]

//>> GET_[QME_RCMR_CORE3_CONTROL_INDEX]
static inline fapi2::buffer<uint64_t>& GET_QME_RCMR_CORE3_CONTROL_INDEX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCMR, QME_RCMR_WO_CLEAR, QME_RCMR_WO_OR));
#endif
    return i_data.extractToRight<QME_RCMR_CORE3_CONTROL_INDEX,
           QME_RCMR_CORE3_CONTROL_INDEX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCMR_CORE3_CONTROL_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCMR_CORE3_CONTROL_INDEX]

//>> PREP_[QME_WCOR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_WCOR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_WCOR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_WCOR]

//>> GET_[QME_WCOR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_WCOR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_WCOR;
#endif
    return fapi2::getScom(i_target, QME_WCOR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_WCOR]

//>> PUT_[QME_WCOR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_WCOR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return fapi2::putScom(i_target, QME_WCOR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_WCOR]


//>> SET_[QME_WCOR_0_OVER_THROTTLED]
static inline fapi2::buffer<uint64_t>& SET_QME_WCOR_0_OVER_THROTTLED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return o_data.insertFromRight<QME_WCOR_0_OVER_THROTTLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_WCOR_0_OVER_THROTTLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_WCOR_0_OVER_THROTTLED]

//>> SET_[QME_WCOR_0_OVER_THROTTLED]
static inline fapi2::buffer<uint64_t>& SET_QME_WCOR_0_OVER_THROTTLED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return o_data.insertFromRight<QME_WCOR_0_OVER_THROTTLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_WCOR_0_OVER_THROTTLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_WCOR_0_OVER_THROTTLED]

//>> SET_[QME_WCOR_0_OVER_THROTTLED]
static inline fapi2::buffer<uint64_t>& SET_QME_WCOR_0_OVER_THROTTLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return o_data.setBit<QME_WCOR_0_OVER_THROTTLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_WCOR_0_OVER_THROTTLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_WCOR_0_OVER_THROTTLED]

//>> CLEAR_[QME_WCOR_0_OVER_THROTTLED]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_WCOR_0_OVER_THROTTLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return o_data.clearBit<QME_WCOR_0_OVER_THROTTLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_WCOR_0_OVER_THROTTLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_WCOR_0_OVER_THROTTLED]

//>> GET_[QME_WCOR_0_OVER_THROTTLED]
static inline fapi2::buffer<uint64_t>& GET_QME_WCOR_0_OVER_THROTTLED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return i_data.extractToRight<QME_WCOR_0_OVER_THROTTLED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_WCOR_0_OVER_THROTTLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_WCOR_0_OVER_THROTTLED]

//>> GET_[QME_WCOR_0_OVER_THROTTLED]
static inline bool GET_QME_WCOR_0_OVER_THROTTLED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return i_data.getBit<QME_WCOR_0_OVER_THROTTLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_WCOR_0_OVER_THROTTLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_WCOR_0_OVER_THROTTLED]

//>> SET_[QME_WCOR_0_THROTTLE_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_WCOR_0_THROTTLE_INDEX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return o_data.insertFromRight<QME_WCOR_0_THROTTLE_INDEX,
           QME_WCOR_0_THROTTLE_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_WCOR_0_THROTTLE_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_WCOR_0_THROTTLE_INDEX]

//>> SET_[QME_WCOR_0_THROTTLE_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_WCOR_0_THROTTLE_INDEX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return o_data.insertFromRight<QME_WCOR_0_THROTTLE_INDEX,
           QME_WCOR_0_THROTTLE_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_WCOR_0_THROTTLE_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_WCOR_0_THROTTLE_INDEX]

//>> GET_[QME_WCOR_0_THROTTLE_INDEX]
static inline fapi2::buffer<uint64_t>& GET_QME_WCOR_0_THROTTLE_INDEX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return i_data.extractToRight<QME_WCOR_0_THROTTLE_INDEX,
           QME_WCOR_0_THROTTLE_INDEX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_WCOR_0_THROTTLE_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_WCOR_0_THROTTLE_INDEX]

//>> SET_[QME_WCOR_1_OVER_THROTTLED]
static inline fapi2::buffer<uint64_t>& SET_QME_WCOR_1_OVER_THROTTLED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return o_data.insertFromRight<QME_WCOR_1_OVER_THROTTLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_WCOR_1_OVER_THROTTLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_WCOR_1_OVER_THROTTLED]

//>> SET_[QME_WCOR_1_OVER_THROTTLED]
static inline fapi2::buffer<uint64_t>& SET_QME_WCOR_1_OVER_THROTTLED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return o_data.insertFromRight<QME_WCOR_1_OVER_THROTTLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_WCOR_1_OVER_THROTTLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_WCOR_1_OVER_THROTTLED]

//>> SET_[QME_WCOR_1_OVER_THROTTLED]
static inline fapi2::buffer<uint64_t>& SET_QME_WCOR_1_OVER_THROTTLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return o_data.setBit<QME_WCOR_1_OVER_THROTTLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_WCOR_1_OVER_THROTTLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_WCOR_1_OVER_THROTTLED]

//>> CLEAR_[QME_WCOR_1_OVER_THROTTLED]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_WCOR_1_OVER_THROTTLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return o_data.clearBit<QME_WCOR_1_OVER_THROTTLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_WCOR_1_OVER_THROTTLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_WCOR_1_OVER_THROTTLED]

//>> GET_[QME_WCOR_1_OVER_THROTTLED]
static inline fapi2::buffer<uint64_t>& GET_QME_WCOR_1_OVER_THROTTLED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return i_data.extractToRight<QME_WCOR_1_OVER_THROTTLED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_WCOR_1_OVER_THROTTLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_WCOR_1_OVER_THROTTLED]

//>> GET_[QME_WCOR_1_OVER_THROTTLED]
static inline bool GET_QME_WCOR_1_OVER_THROTTLED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return i_data.getBit<QME_WCOR_1_OVER_THROTTLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_WCOR_1_OVER_THROTTLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_WCOR_1_OVER_THROTTLED]

//>> SET_[QME_WCOR_1_THROTTLE_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_WCOR_1_THROTTLE_INDEX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return o_data.insertFromRight<QME_WCOR_1_THROTTLE_INDEX,
           QME_WCOR_1_THROTTLE_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_WCOR_1_THROTTLE_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_WCOR_1_THROTTLE_INDEX]

//>> SET_[QME_WCOR_1_THROTTLE_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_WCOR_1_THROTTLE_INDEX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return o_data.insertFromRight<QME_WCOR_1_THROTTLE_INDEX,
           QME_WCOR_1_THROTTLE_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_WCOR_1_THROTTLE_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_WCOR_1_THROTTLE_INDEX]

//>> GET_[QME_WCOR_1_THROTTLE_INDEX]
static inline fapi2::buffer<uint64_t>& GET_QME_WCOR_1_THROTTLE_INDEX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return i_data.extractToRight<QME_WCOR_1_THROTTLE_INDEX,
           QME_WCOR_1_THROTTLE_INDEX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_WCOR_1_THROTTLE_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_WCOR_1_THROTTLE_INDEX]

//>> SET_[QME_WCOR_2_OVER_THROTTLED]
static inline fapi2::buffer<uint64_t>& SET_QME_WCOR_2_OVER_THROTTLED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return o_data.insertFromRight<QME_WCOR_2_OVER_THROTTLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_WCOR_2_OVER_THROTTLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_WCOR_2_OVER_THROTTLED]

//>> SET_[QME_WCOR_2_OVER_THROTTLED]
static inline fapi2::buffer<uint64_t>& SET_QME_WCOR_2_OVER_THROTTLED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return o_data.insertFromRight<QME_WCOR_2_OVER_THROTTLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_WCOR_2_OVER_THROTTLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_WCOR_2_OVER_THROTTLED]

//>> SET_[QME_WCOR_2_OVER_THROTTLED]
static inline fapi2::buffer<uint64_t>& SET_QME_WCOR_2_OVER_THROTTLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return o_data.setBit<QME_WCOR_2_OVER_THROTTLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_WCOR_2_OVER_THROTTLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_WCOR_2_OVER_THROTTLED]

//>> CLEAR_[QME_WCOR_2_OVER_THROTTLED]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_WCOR_2_OVER_THROTTLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return o_data.clearBit<QME_WCOR_2_OVER_THROTTLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_WCOR_2_OVER_THROTTLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_WCOR_2_OVER_THROTTLED]

//>> GET_[QME_WCOR_2_OVER_THROTTLED]
static inline fapi2::buffer<uint64_t>& GET_QME_WCOR_2_OVER_THROTTLED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return i_data.extractToRight<QME_WCOR_2_OVER_THROTTLED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_WCOR_2_OVER_THROTTLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_WCOR_2_OVER_THROTTLED]

//>> GET_[QME_WCOR_2_OVER_THROTTLED]
static inline bool GET_QME_WCOR_2_OVER_THROTTLED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return i_data.getBit<QME_WCOR_2_OVER_THROTTLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_WCOR_2_OVER_THROTTLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_WCOR_2_OVER_THROTTLED]

//>> SET_[QME_WCOR_2_THROTTLE_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_WCOR_2_THROTTLE_INDEX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return o_data.insertFromRight<QME_WCOR_2_THROTTLE_INDEX,
           QME_WCOR_2_THROTTLE_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_WCOR_2_THROTTLE_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_WCOR_2_THROTTLE_INDEX]

//>> SET_[QME_WCOR_2_THROTTLE_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_WCOR_2_THROTTLE_INDEX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return o_data.insertFromRight<QME_WCOR_2_THROTTLE_INDEX,
           QME_WCOR_2_THROTTLE_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_WCOR_2_THROTTLE_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_WCOR_2_THROTTLE_INDEX]

//>> GET_[QME_WCOR_2_THROTTLE_INDEX]
static inline fapi2::buffer<uint64_t>& GET_QME_WCOR_2_THROTTLE_INDEX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return i_data.extractToRight<QME_WCOR_2_THROTTLE_INDEX,
           QME_WCOR_2_THROTTLE_INDEX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_WCOR_2_THROTTLE_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_WCOR_2_THROTTLE_INDEX]

//>> SET_[QME_WCOR_3_OVER_THROTTLED]
static inline fapi2::buffer<uint64_t>& SET_QME_WCOR_3_OVER_THROTTLED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return o_data.insertFromRight<QME_WCOR_3_OVER_THROTTLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_WCOR_3_OVER_THROTTLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_WCOR_3_OVER_THROTTLED]

//>> SET_[QME_WCOR_3_OVER_THROTTLED]
static inline fapi2::buffer<uint64_t>& SET_QME_WCOR_3_OVER_THROTTLED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return o_data.insertFromRight<QME_WCOR_3_OVER_THROTTLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_WCOR_3_OVER_THROTTLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_WCOR_3_OVER_THROTTLED]

//>> SET_[QME_WCOR_3_OVER_THROTTLED]
static inline fapi2::buffer<uint64_t>& SET_QME_WCOR_3_OVER_THROTTLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return o_data.setBit<QME_WCOR_3_OVER_THROTTLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_WCOR_3_OVER_THROTTLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_WCOR_3_OVER_THROTTLED]

//>> CLEAR_[QME_WCOR_3_OVER_THROTTLED]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_WCOR_3_OVER_THROTTLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return o_data.clearBit<QME_WCOR_3_OVER_THROTTLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_WCOR_3_OVER_THROTTLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_WCOR_3_OVER_THROTTLED]

//>> GET_[QME_WCOR_3_OVER_THROTTLED]
static inline fapi2::buffer<uint64_t>& GET_QME_WCOR_3_OVER_THROTTLED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return i_data.extractToRight<QME_WCOR_3_OVER_THROTTLED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_WCOR_3_OVER_THROTTLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_WCOR_3_OVER_THROTTLED]

//>> GET_[QME_WCOR_3_OVER_THROTTLED]
static inline bool GET_QME_WCOR_3_OVER_THROTTLED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return i_data.getBit<QME_WCOR_3_OVER_THROTTLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_WCOR_3_OVER_THROTTLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_WCOR_3_OVER_THROTTLED]

//>> SET_[QME_WCOR_3_THROTTLE_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_WCOR_3_THROTTLE_INDEX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return o_data.insertFromRight<QME_WCOR_3_THROTTLE_INDEX,
           QME_WCOR_3_THROTTLE_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_WCOR_3_THROTTLE_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_WCOR_3_THROTTLE_INDEX]

//>> SET_[QME_WCOR_3_THROTTLE_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_WCOR_3_THROTTLE_INDEX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return o_data.insertFromRight<QME_WCOR_3_THROTTLE_INDEX,
           QME_WCOR_3_THROTTLE_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_WCOR_3_THROTTLE_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_WCOR_3_THROTTLE_INDEX]

//>> GET_[QME_WCOR_3_THROTTLE_INDEX]
static inline fapi2::buffer<uint64_t>& GET_QME_WCOR_3_THROTTLE_INDEX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_WCOR));
#endif
    return i_data.extractToRight<QME_WCOR_3_THROTTLE_INDEX,
           QME_WCOR_3_THROTTLE_INDEX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_WCOR_3_THROTTLE_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_WCOR_3_THROTTLE_INDEX]

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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access RECOV_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access RECOV_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access RECOV_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access RECOV_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access RECOV_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access RECOV_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_MASK_53]

//>> PREP_[XSTOP5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSTOP5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[XSTOP5]

//>> GET_[XSTOP5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSTOP5(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP5;
#endif
    return fapi2::getScom(i_target, XSTOP5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[XSTOP5]

//>> PUT_[XSTOP5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSTOP5(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return fapi2::putScom(i_target, XSTOP5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[XSTOP5]


//>> SET_[XSTOP5_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_ENABLE]

//>> SET_[XSTOP5_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_ENABLE]

//>> SET_[XSTOP5_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.setBit<XSTOP5_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_ENABLE]

//>> CLEAR_[XSTOP5_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP5_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.clearBit<XSTOP5_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP5_ENABLE]

//>> GET_[XSTOP5_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_XSTOP5_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.extractToRight<XSTOP5_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_ENABLE]

//>> GET_[XSTOP5_ENABLE]
static inline bool GET_XSTOP5_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.getBit<XSTOP5_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_ENABLE]

//>> SET_[XSTOP5_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_WAIT_SNOPA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_WAIT_SNOPA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP5_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_WAIT_SNOPA]

//>> SET_[XSTOP5_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_WAIT_SNOPA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_WAIT_SNOPA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP5_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_WAIT_SNOPA]

//>> SET_[XSTOP5_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_WAIT_SNOPA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.setBit<XSTOP5_WAIT_SNOPA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP5_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_WAIT_SNOPA]

//>> CLEAR_[XSTOP5_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP5_WAIT_SNOPA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.clearBit<XSTOP5_WAIT_SNOPA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP5_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP5_WAIT_SNOPA]

//>> GET_[XSTOP5_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& GET_XSTOP5_WAIT_SNOPA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.extractToRight<XSTOP5_WAIT_SNOPA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP5_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_WAIT_SNOPA]

//>> GET_[XSTOP5_WAIT_SNOPA]
static inline bool GET_XSTOP5_WAIT_SNOPA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.getBit<XSTOP5_WAIT_SNOPA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP5_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_WAIT_SNOPA]

//>> SET_[XSTOP5_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_TRIGGER_OPCG_GO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP5_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_TRIGGER_OPCG_GO]

//>> SET_[XSTOP5_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_TRIGGER_OPCG_GO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_TRIGGER_OPCG_GO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP5_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_TRIGGER_OPCG_GO]

//>> SET_[XSTOP5_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.setBit<XSTOP5_TRIGGER_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP5_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_TRIGGER_OPCG_GO]

//>> CLEAR_[XSTOP5_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP5_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.clearBit<XSTOP5_TRIGGER_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP5_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP5_TRIGGER_OPCG_GO]

//>> GET_[XSTOP5_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& GET_XSTOP5_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.extractToRight<XSTOP5_TRIGGER_OPCG_GO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP5_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_TRIGGER_OPCG_GO]

//>> GET_[XSTOP5_TRIGGER_OPCG_GO]
static inline bool GET_XSTOP5_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.getBit<XSTOP5_TRIGGER_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP5_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_TRIGGER_OPCG_GO]

//>> SET_[XSTOP5_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_WAIT_ALWAYS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_WAIT_ALWAYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP5_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_WAIT_ALWAYS]

//>> SET_[XSTOP5_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_WAIT_ALWAYS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_WAIT_ALWAYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP5_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_WAIT_ALWAYS]

//>> SET_[XSTOP5_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_WAIT_ALWAYS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.setBit<XSTOP5_WAIT_ALWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP5_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_WAIT_ALWAYS]

//>> CLEAR_[XSTOP5_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP5_WAIT_ALWAYS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.clearBit<XSTOP5_WAIT_ALWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP5_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP5_WAIT_ALWAYS]

//>> GET_[XSTOP5_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& GET_XSTOP5_WAIT_ALWAYS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.extractToRight<XSTOP5_WAIT_ALWAYS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP5_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_WAIT_ALWAYS]

//>> GET_[XSTOP5_WAIT_ALWAYS]
static inline bool GET_XSTOP5_WAIT_ALWAYS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.getBit<XSTOP5_WAIT_ALWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP5_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_WAIT_ALWAYS]

//>> SET_[XSTOP5_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_PERV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP5_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_PERV]

//>> SET_[XSTOP5_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_PERV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP5_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_PERV]

//>> SET_[XSTOP5_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.setBit<XSTOP5_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP5_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_PERV]

//>> CLEAR_[XSTOP5_REGION_PERV]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP5_REGION_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.clearBit<XSTOP5_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP5_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP5_REGION_PERV]

//>> GET_[XSTOP5_REGION_PERV]
static inline fapi2::buffer<uint64_t>& GET_XSTOP5_REGION_PERV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.extractToRight<XSTOP5_REGION_PERV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP5_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_PERV]

//>> GET_[XSTOP5_REGION_PERV]
static inline bool GET_XSTOP5_REGION_PERV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.getBit<XSTOP5_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP5_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_PERV]

//>> SET_[XSTOP5_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP5_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT1]

//>> SET_[XSTOP5_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP5_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT1]

//>> SET_[XSTOP5_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.setBit<XSTOP5_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP5_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT1]

//>> CLEAR_[XSTOP5_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP5_REGION_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.clearBit<XSTOP5_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP5_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP5_REGION_UNIT1]

//>> GET_[XSTOP5_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& GET_XSTOP5_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.extractToRight<XSTOP5_REGION_UNIT1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP5_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT1]

//>> GET_[XSTOP5_REGION_UNIT1]
static inline bool GET_XSTOP5_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.getBit<XSTOP5_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP5_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT1]

//>> SET_[XSTOP5_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP5_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT2]

//>> SET_[XSTOP5_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP5_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT2]

//>> SET_[XSTOP5_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.setBit<XSTOP5_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP5_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT2]

//>> CLEAR_[XSTOP5_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP5_REGION_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.clearBit<XSTOP5_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP5_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP5_REGION_UNIT2]

//>> GET_[XSTOP5_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& GET_XSTOP5_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.extractToRight<XSTOP5_REGION_UNIT2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP5_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT2]

//>> GET_[XSTOP5_REGION_UNIT2]
static inline bool GET_XSTOP5_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.getBit<XSTOP5_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP5_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT2]

//>> SET_[XSTOP5_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP5_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT3]

//>> SET_[XSTOP5_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP5_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT3]

//>> SET_[XSTOP5_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.setBit<XSTOP5_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP5_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT3]

//>> CLEAR_[XSTOP5_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP5_REGION_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.clearBit<XSTOP5_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP5_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP5_REGION_UNIT3]

//>> GET_[XSTOP5_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& GET_XSTOP5_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.extractToRight<XSTOP5_REGION_UNIT3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP5_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT3]

//>> GET_[XSTOP5_REGION_UNIT3]
static inline bool GET_XSTOP5_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.getBit<XSTOP5_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP5_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT3]

//>> SET_[XSTOP5_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP5_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT4]

//>> SET_[XSTOP5_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP5_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT4]

//>> SET_[XSTOP5_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.setBit<XSTOP5_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP5_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT4]

//>> CLEAR_[XSTOP5_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP5_REGION_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.clearBit<XSTOP5_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP5_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP5_REGION_UNIT4]

//>> GET_[XSTOP5_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& GET_XSTOP5_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.extractToRight<XSTOP5_REGION_UNIT4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP5_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT4]

//>> GET_[XSTOP5_REGION_UNIT4]
static inline bool GET_XSTOP5_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.getBit<XSTOP5_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP5_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT4]

//>> SET_[XSTOP5_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP5_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT5]

//>> SET_[XSTOP5_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP5_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT5]

//>> SET_[XSTOP5_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.setBit<XSTOP5_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP5_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT5]

//>> CLEAR_[XSTOP5_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP5_REGION_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.clearBit<XSTOP5_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP5_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP5_REGION_UNIT5]

//>> GET_[XSTOP5_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& GET_XSTOP5_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.extractToRight<XSTOP5_REGION_UNIT5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP5_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT5]

//>> GET_[XSTOP5_REGION_UNIT5]
static inline bool GET_XSTOP5_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.getBit<XSTOP5_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP5_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT5]

//>> SET_[XSTOP5_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP5_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT6]

//>> SET_[XSTOP5_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP5_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT6]

//>> SET_[XSTOP5_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.setBit<XSTOP5_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP5_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT6]

//>> CLEAR_[XSTOP5_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP5_REGION_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.clearBit<XSTOP5_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP5_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP5_REGION_UNIT6]

//>> GET_[XSTOP5_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& GET_XSTOP5_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.extractToRight<XSTOP5_REGION_UNIT6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP5_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT6]

//>> GET_[XSTOP5_REGION_UNIT6]
static inline bool GET_XSTOP5_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.getBit<XSTOP5_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP5_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT6]

//>> SET_[XSTOP5_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP5_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT7]

//>> SET_[XSTOP5_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP5_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT7]

//>> SET_[XSTOP5_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.setBit<XSTOP5_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP5_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT7]

//>> CLEAR_[XSTOP5_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP5_REGION_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.clearBit<XSTOP5_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP5_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP5_REGION_UNIT7]

//>> GET_[XSTOP5_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& GET_XSTOP5_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.extractToRight<XSTOP5_REGION_UNIT7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP5_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT7]

//>> GET_[XSTOP5_REGION_UNIT7]
static inline bool GET_XSTOP5_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.getBit<XSTOP5_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP5_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT7]

//>> SET_[XSTOP5_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP5_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT8]

//>> SET_[XSTOP5_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP5_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT8]

//>> SET_[XSTOP5_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.setBit<XSTOP5_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP5_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT8]

//>> CLEAR_[XSTOP5_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP5_REGION_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.clearBit<XSTOP5_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP5_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP5_REGION_UNIT8]

//>> GET_[XSTOP5_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& GET_XSTOP5_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.extractToRight<XSTOP5_REGION_UNIT8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP5_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT8]

//>> GET_[XSTOP5_REGION_UNIT8]
static inline bool GET_XSTOP5_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.getBit<XSTOP5_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP5_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT8]

//>> SET_[XSTOP5_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP5_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT9]

//>> SET_[XSTOP5_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP5_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT9]

//>> SET_[XSTOP5_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.setBit<XSTOP5_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP5_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT9]

//>> CLEAR_[XSTOP5_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP5_REGION_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.clearBit<XSTOP5_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP5_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP5_REGION_UNIT9]

//>> GET_[XSTOP5_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& GET_XSTOP5_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.extractToRight<XSTOP5_REGION_UNIT9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP5_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT9]

//>> GET_[XSTOP5_REGION_UNIT9]
static inline bool GET_XSTOP5_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.getBit<XSTOP5_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP5_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT9]

//>> SET_[XSTOP5_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP5_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT10]

//>> SET_[XSTOP5_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP5_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT10]

//>> SET_[XSTOP5_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.setBit<XSTOP5_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP5_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT10]

//>> CLEAR_[XSTOP5_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP5_REGION_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.clearBit<XSTOP5_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP5_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP5_REGION_UNIT10]

//>> GET_[XSTOP5_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& GET_XSTOP5_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.extractToRight<XSTOP5_REGION_UNIT10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP5_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT10]

//>> GET_[XSTOP5_REGION_UNIT10]
static inline bool GET_XSTOP5_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.getBit<XSTOP5_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP5_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT10]

//>> SET_[XSTOP5_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP5_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT11]

//>> SET_[XSTOP5_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP5_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT11]

//>> SET_[XSTOP5_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.setBit<XSTOP5_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP5_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT11]

//>> CLEAR_[XSTOP5_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP5_REGION_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.clearBit<XSTOP5_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP5_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP5_REGION_UNIT11]

//>> GET_[XSTOP5_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& GET_XSTOP5_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.extractToRight<XSTOP5_REGION_UNIT11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP5_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT11]

//>> GET_[XSTOP5_REGION_UNIT11]
static inline bool GET_XSTOP5_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.getBit<XSTOP5_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP5_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT11]

//>> SET_[XSTOP5_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP5_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT12]

//>> SET_[XSTOP5_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP5_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT12]

//>> SET_[XSTOP5_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.setBit<XSTOP5_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP5_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT12]

//>> CLEAR_[XSTOP5_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP5_REGION_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.clearBit<XSTOP5_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP5_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP5_REGION_UNIT12]

//>> GET_[XSTOP5_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& GET_XSTOP5_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.extractToRight<XSTOP5_REGION_UNIT12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP5_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT12]

//>> GET_[XSTOP5_REGION_UNIT12]
static inline bool GET_XSTOP5_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.getBit<XSTOP5_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP5_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT12]

//>> SET_[XSTOP5_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP5_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT13]

//>> SET_[XSTOP5_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP5_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT13]

//>> SET_[XSTOP5_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.setBit<XSTOP5_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP5_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT13]

//>> CLEAR_[XSTOP5_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP5_REGION_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.clearBit<XSTOP5_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP5_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP5_REGION_UNIT13]

//>> GET_[XSTOP5_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& GET_XSTOP5_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.extractToRight<XSTOP5_REGION_UNIT13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP5_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT13]

//>> GET_[XSTOP5_REGION_UNIT13]
static inline bool GET_XSTOP5_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.getBit<XSTOP5_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP5_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT13]

//>> SET_[XSTOP5_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP5_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT14]

//>> SET_[XSTOP5_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_REGION_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP5_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT14]

//>> SET_[XSTOP5_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_REGION_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.setBit<XSTOP5_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP5_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_REGION_UNIT14]

//>> CLEAR_[XSTOP5_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP5_REGION_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.clearBit<XSTOP5_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP5_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP5_REGION_UNIT14]

//>> GET_[XSTOP5_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& GET_XSTOP5_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.extractToRight<XSTOP5_REGION_UNIT14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP5_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT14]

//>> GET_[XSTOP5_REGION_UNIT14]
static inline bool GET_XSTOP5_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.getBit<XSTOP5_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP5_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_REGION_UNIT14]

//>> SET_[XSTOP5_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_WAIT_CYCLES,
           XSTOP5_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP5_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_WAIT_CYCLES]

//>> SET_[XSTOP5_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_XSTOP5_WAIT_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return o_data.insertFromRight<XSTOP5_WAIT_CYCLES,
           XSTOP5_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP5_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP5_WAIT_CYCLES]

//>> GET_[XSTOP5_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& GET_XSTOP5_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP5));
#endif
    return i_data.extractToRight<XSTOP5_WAIT_CYCLES,
           XSTOP5_WAIT_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP5_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP5_WAIT_CYCLES]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
