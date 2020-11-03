/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00048.H $         */
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

#ifndef __IOHS_REG00048_H_
#define __IOHS_REG00048_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> PREP_[ATOMIC_LOCK_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ATOMIC_LOCK_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATOMIC_LOCK_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[ATOMIC_LOCK_REG]

//>> GET_[ATOMIC_LOCK_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ATOMIC_LOCK_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATOMIC_LOCK_REG;
#endif
    return fapi2::getScom(i_target, ATOMIC_LOCK_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[ATOMIC_LOCK_REG]

//>> PUT_[ATOMIC_LOCK_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ATOMIC_LOCK_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return fapi2::putScom(i_target, ATOMIC_LOCK_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[ATOMIC_LOCK_REG]


//>> SET_[ATOMIC_LOCK_REG_LOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_ATOMIC_LOCK_REG_LOCK_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return o_data.insertFromRight<ATOMIC_LOCK_REG_LOCK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ATOMIC_LOCK_REG_LOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATOMIC_LOCK_REG_LOCK_ENABLE]

//>> SET_[ATOMIC_LOCK_REG_LOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_ATOMIC_LOCK_REG_LOCK_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return o_data.insertFromRight<ATOMIC_LOCK_REG_LOCK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ATOMIC_LOCK_REG_LOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATOMIC_LOCK_REG_LOCK_ENABLE]

//>> SET_[ATOMIC_LOCK_REG_LOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_ATOMIC_LOCK_REG_LOCK_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return o_data.setBit<ATOMIC_LOCK_REG_LOCK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ATOMIC_LOCK_REG_LOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATOMIC_LOCK_REG_LOCK_ENABLE]

//>> CLEAR_[ATOMIC_LOCK_REG_LOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_ATOMIC_LOCK_REG_LOCK_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return o_data.clearBit<ATOMIC_LOCK_REG_LOCK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ATOMIC_LOCK_REG_LOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATOMIC_LOCK_REG_LOCK_ENABLE]

//>> GET_[ATOMIC_LOCK_REG_LOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_ATOMIC_LOCK_REG_LOCK_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return i_data.extractToRight<ATOMIC_LOCK_REG_LOCK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ATOMIC_LOCK_REG_LOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATOMIC_LOCK_REG_LOCK_ENABLE]

//>> GET_[ATOMIC_LOCK_REG_LOCK_ENABLE]
static inline bool GET_ATOMIC_LOCK_REG_LOCK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return i_data.getBit<ATOMIC_LOCK_REG_LOCK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ATOMIC_LOCK_REG_LOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATOMIC_LOCK_REG_LOCK_ENABLE]

//>> SET_[ATOMIC_LOCK_REG_ID]
static inline fapi2::buffer<uint64_t>& SET_ATOMIC_LOCK_REG_ID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return o_data.insertFromRight<ATOMIC_LOCK_REG_ID,
           ATOMIC_LOCK_REG_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ATOMIC_LOCK_REG_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATOMIC_LOCK_REG_ID]

//>> SET_[ATOMIC_LOCK_REG_ID]
static inline fapi2::buffer<uint64_t>& SET_ATOMIC_LOCK_REG_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return o_data.insertFromRight<ATOMIC_LOCK_REG_ID,
           ATOMIC_LOCK_REG_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ATOMIC_LOCK_REG_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATOMIC_LOCK_REG_ID]

//>> GET_[ATOMIC_LOCK_REG_ID]
static inline fapi2::buffer<uint64_t>& GET_ATOMIC_LOCK_REG_ID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return i_data.extractToRight<ATOMIC_LOCK_REG_ID,
           ATOMIC_LOCK_REG_ID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ATOMIC_LOCK_REG_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATOMIC_LOCK_REG_ID]

//>> SET_[ATOMIC_LOCK_REG_ACTIVITY]
static inline fapi2::buffer<uint64_t>& SET_ATOMIC_LOCK_REG_ACTIVITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return o_data.insertFromRight<ATOMIC_LOCK_REG_ACTIVITY,
           ATOMIC_LOCK_REG_ACTIVITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ATOMIC_LOCK_REG_ACTIVITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATOMIC_LOCK_REG_ACTIVITY]

//>> SET_[ATOMIC_LOCK_REG_ACTIVITY]
static inline fapi2::buffer<uint64_t>& SET_ATOMIC_LOCK_REG_ACTIVITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return o_data.insertFromRight<ATOMIC_LOCK_REG_ACTIVITY,
           ATOMIC_LOCK_REG_ACTIVITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ATOMIC_LOCK_REG_ACTIVITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATOMIC_LOCK_REG_ACTIVITY]

//>> GET_[ATOMIC_LOCK_REG_ACTIVITY]
static inline fapi2::buffer<uint64_t>& GET_ATOMIC_LOCK_REG_ACTIVITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return i_data.extractToRight<ATOMIC_LOCK_REG_ACTIVITY,
           ATOMIC_LOCK_REG_ACTIVITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ATOMIC_LOCK_REG_ACTIVITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATOMIC_LOCK_REG_ACTIVITY]

//>> PREP_[ATTN_INTERRUPT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ATTN_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATTN_INTERRUPT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[ATTN_INTERRUPT_REG]

//>> GET_[ATTN_INTERRUPT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ATTN_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATTN_INTERRUPT_REG;
#endif
    return fapi2::getScom(i_target, ATTN_INTERRUPT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[ATTN_INTERRUPT_REG]

//>> PUT_[ATTN_INTERRUPT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ATTN_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(ATTN_INTERRUPT_REG));
#endif
    return fapi2::putScom(i_target, ATTN_INTERRUPT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[ATTN_INTERRUPT_REG]


//>> SET_[ATTN_INTERRUPT_REG_ATTN]
static inline fapi2::buffer<uint64_t>& SET_ATTN_INTERRUPT_REG_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATTN_INTERRUPT_REG));
#endif
    return o_data.insertFromRight<ATTN_INTERRUPT_REG_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access ATTN_INTERRUPT_REG_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATTN_INTERRUPT_REG_ATTN]

//>> SET_[ATTN_INTERRUPT_REG_ATTN]
static inline fapi2::buffer<uint64_t>& SET_ATTN_INTERRUPT_REG_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATTN_INTERRUPT_REG));
#endif
    return o_data.insertFromRight<ATTN_INTERRUPT_REG_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access ATTN_INTERRUPT_REG_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATTN_INTERRUPT_REG_ATTN]

//>> SET_[ATTN_INTERRUPT_REG_ATTN]
static inline fapi2::buffer<uint64_t>& SET_ATTN_INTERRUPT_REG_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATTN_INTERRUPT_REG));
#endif
    return o_data.setBit<ATTN_INTERRUPT_REG_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access ATTN_INTERRUPT_REG_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATTN_INTERRUPT_REG_ATTN]

//>> CLEAR_[ATTN_INTERRUPT_REG_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_ATTN_INTERRUPT_REG_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATTN_INTERRUPT_REG));
#endif
    return o_data.clearBit<ATTN_INTERRUPT_REG_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access ATTN_INTERRUPT_REG_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATTN_INTERRUPT_REG_ATTN]

//>> GET_[ATTN_INTERRUPT_REG_ATTN]
static inline fapi2::buffer<uint64_t>& GET_ATTN_INTERRUPT_REG_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATTN_INTERRUPT_REG));
#endif
    return i_data.extractToRight<ATTN_INTERRUPT_REG_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access ATTN_INTERRUPT_REG_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATTN_INTERRUPT_REG_ATTN]

//>> GET_[ATTN_INTERRUPT_REG_ATTN]
static inline bool GET_ATTN_INTERRUPT_REG_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATTN_INTERRUPT_REG));
#endif
    return i_data.getBit<ATTN_INTERRUPT_REG_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access ATTN_INTERRUPT_REG_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATTN_INTERRUPT_REG_ATTN]

//>> PREP_[DLP_LINK1_RX_LANE_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_LINK1_RX_LANE_CONTROL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_LINK1_RX_LANE_CONTROL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLP_LINK1_RX_LANE_CONTROL]

//>> GET_[DLP_LINK1_RX_LANE_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_LINK1_RX_LANE_CONTROL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_LINK1_RX_LANE_CONTROL;
#endif
    return fapi2::getScom(i_target, DLP_LINK1_RX_LANE_CONTROL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLP_LINK1_RX_LANE_CONTROL]

//>> PUT_[DLP_LINK1_RX_LANE_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_LINK1_RX_LANE_CONTROL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_RX_LANE_CONTROL));
#endif
    return fapi2::putScom(i_target, DLP_LINK1_RX_LANE_CONTROL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLP_LINK1_RX_LANE_CONTROL]


//>> SET_[DLP_LINK1_RX_LANE_CONTROL_DISABLED]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_RX_LANE_CONTROL_DISABLED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_RX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_RX_LANE_CONTROL_DISABLED,
           DLP_LINK1_RX_LANE_CONTROL_DISABLED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_RX_LANE_CONTROL_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_RX_LANE_CONTROL_DISABLED]

//>> SET_[DLP_LINK1_RX_LANE_CONTROL_DISABLED]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_RX_LANE_CONTROL_DISABLED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_RX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_RX_LANE_CONTROL_DISABLED,
           DLP_LINK1_RX_LANE_CONTROL_DISABLED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_RX_LANE_CONTROL_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_RX_LANE_CONTROL_DISABLED]

//>> GET_[DLP_LINK1_RX_LANE_CONTROL_DISABLED]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_RX_LANE_CONTROL_DISABLED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_RX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK1_RX_LANE_CONTROL_DISABLED,
           DLP_LINK1_RX_LANE_CONTROL_DISABLED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_RX_LANE_CONTROL_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_RX_LANE_CONTROL_DISABLED]

//>> SET_[DLP_LINK1_RX_LANE_CONTROL_BRINGUP]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_RX_LANE_CONTROL_BRINGUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_RX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_RX_LANE_CONTROL_BRINGUP,
           DLP_LINK1_RX_LANE_CONTROL_BRINGUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_RX_LANE_CONTROL_BRINGUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_RX_LANE_CONTROL_BRINGUP]

//>> SET_[DLP_LINK1_RX_LANE_CONTROL_BRINGUP]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_RX_LANE_CONTROL_BRINGUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_RX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_RX_LANE_CONTROL_BRINGUP,
           DLP_LINK1_RX_LANE_CONTROL_BRINGUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_RX_LANE_CONTROL_BRINGUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_RX_LANE_CONTROL_BRINGUP]

//>> GET_[DLP_LINK1_RX_LANE_CONTROL_BRINGUP]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_RX_LANE_CONTROL_BRINGUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_RX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK1_RX_LANE_CONTROL_BRINGUP,
           DLP_LINK1_RX_LANE_CONTROL_BRINGUP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_RX_LANE_CONTROL_BRINGUP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_RX_LANE_CONTROL_BRINGUP]

//>> SET_[DLP_LINK1_RX_LANE_CONTROL_SPARED]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_RX_LANE_CONTROL_SPARED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_RX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_RX_LANE_CONTROL_SPARED,
           DLP_LINK1_RX_LANE_CONTROL_SPARED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_RX_LANE_CONTROL_SPARED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_RX_LANE_CONTROL_SPARED]

//>> SET_[DLP_LINK1_RX_LANE_CONTROL_SPARED]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_RX_LANE_CONTROL_SPARED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_RX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_RX_LANE_CONTROL_SPARED,
           DLP_LINK1_RX_LANE_CONTROL_SPARED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_RX_LANE_CONTROL_SPARED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_RX_LANE_CONTROL_SPARED]

//>> GET_[DLP_LINK1_RX_LANE_CONTROL_SPARED]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_RX_LANE_CONTROL_SPARED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_RX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK1_RX_LANE_CONTROL_SPARED,
           DLP_LINK1_RX_LANE_CONTROL_SPARED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_RX_LANE_CONTROL_SPARED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_RX_LANE_CONTROL_SPARED]

//>> SET_[DLP_LINK1_RX_LANE_CONTROL_LOCKED]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_RX_LANE_CONTROL_LOCKED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_RX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_RX_LANE_CONTROL_LOCKED,
           DLP_LINK1_RX_LANE_CONTROL_LOCKED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_RX_LANE_CONTROL_LOCKED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_RX_LANE_CONTROL_LOCKED]

//>> SET_[DLP_LINK1_RX_LANE_CONTROL_LOCKED]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_RX_LANE_CONTROL_LOCKED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_RX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_RX_LANE_CONTROL_LOCKED,
           DLP_LINK1_RX_LANE_CONTROL_LOCKED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_RX_LANE_CONTROL_LOCKED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_RX_LANE_CONTROL_LOCKED]

//>> GET_[DLP_LINK1_RX_LANE_CONTROL_LOCKED]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_RX_LANE_CONTROL_LOCKED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_RX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK1_RX_LANE_CONTROL_LOCKED,
           DLP_LINK1_RX_LANE_CONTROL_LOCKED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_RX_LANE_CONTROL_LOCKED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_RX_LANE_CONTROL_LOCKED]

//>> SET_[DLP_LINK1_RX_LANE_CONTROL_FAILED]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_RX_LANE_CONTROL_FAILED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_RX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_RX_LANE_CONTROL_FAILED,
           DLP_LINK1_RX_LANE_CONTROL_FAILED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_RX_LANE_CONTROL_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_RX_LANE_CONTROL_FAILED]

//>> SET_[DLP_LINK1_RX_LANE_CONTROL_FAILED]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_RX_LANE_CONTROL_FAILED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_RX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_RX_LANE_CONTROL_FAILED,
           DLP_LINK1_RX_LANE_CONTROL_FAILED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_RX_LANE_CONTROL_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_RX_LANE_CONTROL_FAILED]

//>> GET_[DLP_LINK1_RX_LANE_CONTROL_FAILED]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_RX_LANE_CONTROL_FAILED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_RX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK1_RX_LANE_CONTROL_FAILED,
           DLP_LINK1_RX_LANE_CONTROL_FAILED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_RX_LANE_CONTROL_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_RX_LANE_CONTROL_FAILED]

//>> SET_[DLP_LINK1_RX_LANE_CONTROL_ERROR_STATUS]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_RX_LANE_CONTROL_ERROR_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_RX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_RX_LANE_CONTROL_ERROR_STATUS,
           DLP_LINK1_RX_LANE_CONTROL_ERROR_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_RX_LANE_CONTROL_ERROR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_RX_LANE_CONTROL_ERROR_STATUS]

//>> SET_[DLP_LINK1_RX_LANE_CONTROL_ERROR_STATUS]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_RX_LANE_CONTROL_ERROR_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_RX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_RX_LANE_CONTROL_ERROR_STATUS,
           DLP_LINK1_RX_LANE_CONTROL_ERROR_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_RX_LANE_CONTROL_ERROR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_RX_LANE_CONTROL_ERROR_STATUS]

//>> GET_[DLP_LINK1_RX_LANE_CONTROL_ERROR_STATUS]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_RX_LANE_CONTROL_ERROR_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_RX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK1_RX_LANE_CONTROL_ERROR_STATUS,
           DLP_LINK1_RX_LANE_CONTROL_ERROR_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_RX_LANE_CONTROL_ERROR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_RX_LANE_CONTROL_ERROR_STATUS]

//>> PREP_[DLX_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLX_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    scomt::last_scom = DLX_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLX_CONFIG]

//>> GET_[DLX_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLX_CONFIG(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    scomt::last_scom = DLX_CONFIG;
#endif
    return fapi2::getScom(i_target, DLX_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLX_CONFIG]

//>> PUT_[DLX_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLX_CONFIG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLX_CONFIG));
#endif
    return fapi2::putScom(i_target, DLX_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLX_CONFIG]


//>> SET_[P10_20_DLX_CONFIG_CFG_DLX1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLX_CONFIG_CFG_DLX1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLX_CONFIG));
#endif
    return o_data.insertFromRight<P10_20_DLX_CONFIG_CFG_DLX1,
           P10_20_DLX_CONFIG_CFG_DLX1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLX_CONFIG_CFG_DLX1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLX_CONFIG_CFG_DLX1]

//>> SET_[P10_20_DLX_CONFIG_CFG_DLX1]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLX_CONFIG_CFG_DLX1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLX_CONFIG));
#endif
    return o_data.insertFromRight<P10_20_DLX_CONFIG_CFG_DLX1,
           P10_20_DLX_CONFIG_CFG_DLX1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLX_CONFIG_CFG_DLX1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLX_CONFIG_CFG_DLX1]

//>> GET_[P10_20_DLX_CONFIG_CFG_DLX1]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLX_CONFIG_CFG_DLX1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLX_CONFIG));
#endif
    return i_data.extractToRight<P10_20_DLX_CONFIG_CFG_DLX1,
           P10_20_DLX_CONFIG_CFG_DLX1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLX_CONFIG_CFG_DLX1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLX_CONFIG_CFG_DLX1]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
