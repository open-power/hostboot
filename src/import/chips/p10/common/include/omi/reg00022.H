/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omi/reg00022.H $          */
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

#ifndef __OMI_REG00022_H_
#define __OMI_REG00022_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


//>> PREP_[CONFIG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CONFIG0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CONFIG0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CONFIG0]

//>> GET_[CONFIG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CONFIG0(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CONFIG0;
#endif
    return fapi2::getScom(i_target, CONFIG0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CONFIG0]

//>> PUT_[CONFIG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CONFIG0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return fapi2::putScom(i_target, CONFIG0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CONFIG0]


//>> SET_[CONFIG0_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_ENABLE]

//>> SET_[CONFIG0_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_ENABLE]

//>> SET_[CONFIG0_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.setBit<CONFIG0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CONFIG0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_ENABLE]

//>> CLEAR_[CONFIG0_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.clearBit<CONFIG0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CONFIG0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CONFIG0_ENABLE]

//>> GET_[CONFIG0_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_ENABLE]

//>> GET_[CONFIG0_ENABLE]
static inline bool GET_CONFIG0_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.getBit<CONFIG0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CONFIG0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_ENABLE]

//>> SET_[CONFIG0_CFG_SPARE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_CFG_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_CFG_SPARE,
           CONFIG0_CFG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_CFG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_CFG_SPARE]

//>> SET_[CONFIG0_CFG_SPARE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_CFG_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_CFG_SPARE,
           CONFIG0_CFG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_CFG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_CFG_SPARE]

//>> GET_[CONFIG0_CFG_SPARE]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_CFG_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_CFG_SPARE,
           CONFIG0_CFG_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_CFG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_CFG_SPARE]

//>> SET_[CONFIG0_CFG_TL_CREDITS]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_CFG_TL_CREDITS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_CFG_TL_CREDITS,
           CONFIG0_CFG_TL_CREDITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_CFG_TL_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_CFG_TL_CREDITS]

//>> SET_[CONFIG0_CFG_TL_CREDITS]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_CFG_TL_CREDITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_CFG_TL_CREDITS,
           CONFIG0_CFG_TL_CREDITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_CFG_TL_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_CFG_TL_CREDITS]

//>> GET_[CONFIG0_CFG_TL_CREDITS]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_CFG_TL_CREDITS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_CFG_TL_CREDITS,
           CONFIG0_CFG_TL_CREDITS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_CFG_TL_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_CFG_TL_CREDITS]

//>> SET_[CONFIG0_TL_EVENT_ACTIONS]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_TL_EVENT_ACTIONS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_TL_EVENT_ACTIONS,
           CONFIG0_TL_EVENT_ACTIONS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_TL_EVENT_ACTIONS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_TL_EVENT_ACTIONS]

//>> SET_[CONFIG0_TL_EVENT_ACTIONS]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_TL_EVENT_ACTIONS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_TL_EVENT_ACTIONS,
           CONFIG0_TL_EVENT_ACTIONS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_TL_EVENT_ACTIONS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_TL_EVENT_ACTIONS]

//>> GET_[CONFIG0_TL_EVENT_ACTIONS]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_TL_EVENT_ACTIONS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_TL_EVENT_ACTIONS,
           CONFIG0_TL_EVENT_ACTIONS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_TL_EVENT_ACTIONS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_TL_EVENT_ACTIONS]

//>> SET_[CONFIG0_TL_ERROR_ACTIONS]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_TL_ERROR_ACTIONS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_TL_ERROR_ACTIONS,
           CONFIG0_TL_ERROR_ACTIONS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_TL_ERROR_ACTIONS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_TL_ERROR_ACTIONS]

//>> SET_[CONFIG0_TL_ERROR_ACTIONS]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_TL_ERROR_ACTIONS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_TL_ERROR_ACTIONS,
           CONFIG0_TL_ERROR_ACTIONS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_TL_ERROR_ACTIONS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_TL_ERROR_ACTIONS]

//>> GET_[CONFIG0_TL_ERROR_ACTIONS]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_TL_ERROR_ACTIONS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_TL_ERROR_ACTIONS,
           CONFIG0_TL_ERROR_ACTIONS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_TL_ERROR_ACTIONS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_TL_ERROR_ACTIONS]

//>> SET_[CONFIG0_FWD_PROGRESS_TIMER]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_FWD_PROGRESS_TIMER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_FWD_PROGRESS_TIMER,
           CONFIG0_FWD_PROGRESS_TIMER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_FWD_PROGRESS_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_FWD_PROGRESS_TIMER]

//>> SET_[CONFIG0_FWD_PROGRESS_TIMER]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_FWD_PROGRESS_TIMER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_FWD_PROGRESS_TIMER,
           CONFIG0_FWD_PROGRESS_TIMER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_FWD_PROGRESS_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_FWD_PROGRESS_TIMER]

//>> GET_[CONFIG0_FWD_PROGRESS_TIMER]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_FWD_PROGRESS_TIMER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_FWD_PROGRESS_TIMER,
           CONFIG0_FWD_PROGRESS_TIMER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_FWD_PROGRESS_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_FWD_PROGRESS_TIMER]

//>> SET_[CONFIG0_REPLAY_RSVD_ENTRIES]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_REPLAY_RSVD_ENTRIES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_REPLAY_RSVD_ENTRIES,
           CONFIG0_REPLAY_RSVD_ENTRIES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_REPLAY_RSVD_ENTRIES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_REPLAY_RSVD_ENTRIES]

//>> SET_[CONFIG0_REPLAY_RSVD_ENTRIES]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_REPLAY_RSVD_ENTRIES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_REPLAY_RSVD_ENTRIES,
           CONFIG0_REPLAY_RSVD_ENTRIES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_REPLAY_RSVD_ENTRIES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_REPLAY_RSVD_ENTRIES]

//>> GET_[CONFIG0_REPLAY_RSVD_ENTRIES]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_REPLAY_RSVD_ENTRIES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_REPLAY_RSVD_ENTRIES,
           CONFIG0_REPLAY_RSVD_ENTRIES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_REPLAY_RSVD_ENTRIES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_REPLAY_RSVD_ENTRIES]

//>> SET_[CONFIG0_DEBUG_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_DEBUG_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_DEBUG_SELECT,
           CONFIG0_DEBUG_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_DEBUG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_DEBUG_SELECT]

//>> SET_[CONFIG0_DEBUG_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_DEBUG_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_DEBUG_SELECT,
           CONFIG0_DEBUG_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_DEBUG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_DEBUG_SELECT]

//>> GET_[CONFIG0_DEBUG_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_DEBUG_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_DEBUG_SELECT,
           CONFIG0_DEBUG_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_DEBUG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_DEBUG_SELECT]

//>> SET_[CONFIG0_DEBUG_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_DEBUG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_DEBUG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_DEBUG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_DEBUG_ENABLE]

//>> SET_[CONFIG0_DEBUG_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_DEBUG_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_DEBUG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_DEBUG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_DEBUG_ENABLE]

//>> SET_[CONFIG0_DEBUG_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_DEBUG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.setBit<CONFIG0_DEBUG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CONFIG0_DEBUG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_DEBUG_ENABLE]

//>> CLEAR_[CONFIG0_DEBUG_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG0_DEBUG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.clearBit<CONFIG0_DEBUG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CONFIG0_DEBUG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CONFIG0_DEBUG_ENABLE]

//>> GET_[CONFIG0_DEBUG_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_DEBUG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_DEBUG_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_DEBUG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_DEBUG_ENABLE]

//>> GET_[CONFIG0_DEBUG_ENABLE]
static inline bool GET_CONFIG0_DEBUG_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.getBit<CONFIG0_DEBUG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CONFIG0_DEBUG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_DEBUG_ENABLE]

//>> SET_[CONFIG0_DL2TL_DATA_PARITY_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_DL2TL_DATA_PARITY_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_DL2TL_DATA_PARITY_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_DL2TL_DATA_PARITY_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_DL2TL_DATA_PARITY_INJECT]

//>> SET_[CONFIG0_DL2TL_DATA_PARITY_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_DL2TL_DATA_PARITY_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_DL2TL_DATA_PARITY_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_DL2TL_DATA_PARITY_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_DL2TL_DATA_PARITY_INJECT]

//>> SET_[CONFIG0_DL2TL_DATA_PARITY_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_DL2TL_DATA_PARITY_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.setBit<CONFIG0_DL2TL_DATA_PARITY_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CONFIG0_DL2TL_DATA_PARITY_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_DL2TL_DATA_PARITY_INJECT]

//>> CLEAR_[CONFIG0_DL2TL_DATA_PARITY_INJECT]
static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG0_DL2TL_DATA_PARITY_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.clearBit<CONFIG0_DL2TL_DATA_PARITY_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CONFIG0_DL2TL_DATA_PARITY_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CONFIG0_DL2TL_DATA_PARITY_INJECT]

//>> GET_[CONFIG0_DL2TL_DATA_PARITY_INJECT]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_DL2TL_DATA_PARITY_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_DL2TL_DATA_PARITY_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_DL2TL_DATA_PARITY_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_DL2TL_DATA_PARITY_INJECT]

//>> GET_[CONFIG0_DL2TL_DATA_PARITY_INJECT]
static inline bool GET_CONFIG0_DL2TL_DATA_PARITY_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.getBit<CONFIG0_DL2TL_DATA_PARITY_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CONFIG0_DL2TL_DATA_PARITY_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_DL2TL_DATA_PARITY_INJECT]

//>> SET_[CONFIG0_DL2TL_CONTROL_PARITY_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_DL2TL_CONTROL_PARITY_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_DL2TL_CONTROL_PARITY_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_DL2TL_CONTROL_PARITY_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_DL2TL_CONTROL_PARITY_INJECT]

//>> SET_[CONFIG0_DL2TL_CONTROL_PARITY_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_DL2TL_CONTROL_PARITY_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_DL2TL_CONTROL_PARITY_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_DL2TL_CONTROL_PARITY_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_DL2TL_CONTROL_PARITY_INJECT]

//>> SET_[CONFIG0_DL2TL_CONTROL_PARITY_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_DL2TL_CONTROL_PARITY_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.setBit<CONFIG0_DL2TL_CONTROL_PARITY_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CONFIG0_DL2TL_CONTROL_PARITY_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_DL2TL_CONTROL_PARITY_INJECT]

//>> CLEAR_[CONFIG0_DL2TL_CONTROL_PARITY_INJECT]
static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG0_DL2TL_CONTROL_PARITY_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.clearBit<CONFIG0_DL2TL_CONTROL_PARITY_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CONFIG0_DL2TL_CONTROL_PARITY_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CONFIG0_DL2TL_CONTROL_PARITY_INJECT]

//>> GET_[CONFIG0_DL2TL_CONTROL_PARITY_INJECT]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_DL2TL_CONTROL_PARITY_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_DL2TL_CONTROL_PARITY_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_DL2TL_CONTROL_PARITY_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_DL2TL_CONTROL_PARITY_INJECT]

//>> GET_[CONFIG0_DL2TL_CONTROL_PARITY_INJECT]
static inline bool GET_CONFIG0_DL2TL_CONTROL_PARITY_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.getBit<CONFIG0_DL2TL_CONTROL_PARITY_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CONFIG0_DL2TL_CONTROL_PARITY_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_DL2TL_CONTROL_PARITY_INJECT]

//>> SET_[CONFIG0_ECC_UE_INJECTION]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_ECC_UE_INJECTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_ECC_UE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_ECC_UE_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_ECC_UE_INJECTION]

//>> SET_[CONFIG0_ECC_UE_INJECTION]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_ECC_UE_INJECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_ECC_UE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_ECC_UE_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_ECC_UE_INJECTION]

//>> SET_[CONFIG0_ECC_UE_INJECTION]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_ECC_UE_INJECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.setBit<CONFIG0_ECC_UE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CONFIG0_ECC_UE_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_ECC_UE_INJECTION]

//>> CLEAR_[CONFIG0_ECC_UE_INJECTION]
static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG0_ECC_UE_INJECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.clearBit<CONFIG0_ECC_UE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CONFIG0_ECC_UE_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CONFIG0_ECC_UE_INJECTION]

//>> GET_[CONFIG0_ECC_UE_INJECTION]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_ECC_UE_INJECTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_ECC_UE_INJECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_ECC_UE_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_ECC_UE_INJECTION]

//>> GET_[CONFIG0_ECC_UE_INJECTION]
static inline bool GET_CONFIG0_ECC_UE_INJECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.getBit<CONFIG0_ECC_UE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CONFIG0_ECC_UE_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_ECC_UE_INJECTION]

//>> SET_[CONFIG0_ECC_CE_INJECTION]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_ECC_CE_INJECTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_ECC_CE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_ECC_CE_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_ECC_CE_INJECTION]

//>> SET_[CONFIG0_ECC_CE_INJECTION]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_ECC_CE_INJECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_ECC_CE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_ECC_CE_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_ECC_CE_INJECTION]

//>> SET_[CONFIG0_ECC_CE_INJECTION]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_ECC_CE_INJECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.setBit<CONFIG0_ECC_CE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CONFIG0_ECC_CE_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_ECC_CE_INJECTION]

//>> CLEAR_[CONFIG0_ECC_CE_INJECTION]
static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG0_ECC_CE_INJECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.clearBit<CONFIG0_ECC_CE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CONFIG0_ECC_CE_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CONFIG0_ECC_CE_INJECTION]

//>> GET_[CONFIG0_ECC_CE_INJECTION]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_ECC_CE_INJECTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_ECC_CE_INJECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_ECC_CE_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_ECC_CE_INJECTION]

//>> GET_[CONFIG0_ECC_CE_INJECTION]
static inline bool GET_CONFIG0_ECC_CE_INJECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.getBit<CONFIG0_ECC_CE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CONFIG0_ECC_CE_INJECTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_ECC_CE_INJECTION]

//>> SET_[CONFIG0_FP_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_FP_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_FP_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_FP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_FP_DISABLE]

//>> SET_[CONFIG0_FP_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_FP_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_FP_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_FP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_FP_DISABLE]

//>> SET_[CONFIG0_FP_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_FP_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.setBit<CONFIG0_FP_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CONFIG0_FP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_FP_DISABLE]

//>> CLEAR_[CONFIG0_FP_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG0_FP_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.clearBit<CONFIG0_FP_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CONFIG0_FP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CONFIG0_FP_DISABLE]

//>> GET_[CONFIG0_FP_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_FP_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_FP_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_FP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_FP_DISABLE]

//>> GET_[CONFIG0_FP_DISABLE]
static inline bool GET_CONFIG0_FP_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.getBit<CONFIG0_FP_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CONFIG0_FP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_FP_DISABLE]

//>> SET_[CONFIG0_TX_LN_REV_ENA]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_TX_LN_REV_ENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_TX_LN_REV_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_TX_LN_REV_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_TX_LN_REV_ENA]

//>> SET_[CONFIG0_TX_LN_REV_ENA]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_TX_LN_REV_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_TX_LN_REV_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_TX_LN_REV_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_TX_LN_REV_ENA]

//>> SET_[CONFIG0_TX_LN_REV_ENA]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_TX_LN_REV_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.setBit<CONFIG0_TX_LN_REV_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CONFIG0_TX_LN_REV_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_TX_LN_REV_ENA]

//>> CLEAR_[CONFIG0_TX_LN_REV_ENA]
static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG0_TX_LN_REV_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.clearBit<CONFIG0_TX_LN_REV_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CONFIG0_TX_LN_REV_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CONFIG0_TX_LN_REV_ENA]

//>> GET_[CONFIG0_TX_LN_REV_ENA]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_TX_LN_REV_ENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_TX_LN_REV_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_TX_LN_REV_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_TX_LN_REV_ENA]

//>> GET_[CONFIG0_TX_LN_REV_ENA]
static inline bool GET_CONFIG0_TX_LN_REV_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.getBit<CONFIG0_TX_LN_REV_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CONFIG0_TX_LN_REV_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_TX_LN_REV_ENA]

//>> SET_[CONFIG0_128_130_ENCODING_ENABLED]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_128_130_ENCODING_ENABLED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_128_130_ENCODING_ENABLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_128_130_ENCODING_ENABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_128_130_ENCODING_ENABLED]

//>> SET_[CONFIG0_128_130_ENCODING_ENABLED]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_128_130_ENCODING_ENABLED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_128_130_ENCODING_ENABLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_128_130_ENCODING_ENABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_128_130_ENCODING_ENABLED]

//>> SET_[CONFIG0_128_130_ENCODING_ENABLED]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_128_130_ENCODING_ENABLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.setBit<CONFIG0_128_130_ENCODING_ENABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CONFIG0_128_130_ENCODING_ENABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_128_130_ENCODING_ENABLED]

//>> CLEAR_[CONFIG0_128_130_ENCODING_ENABLED]
static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG0_128_130_ENCODING_ENABLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.clearBit<CONFIG0_128_130_ENCODING_ENABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CONFIG0_128_130_ENCODING_ENABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CONFIG0_128_130_ENCODING_ENABLED]

//>> GET_[CONFIG0_128_130_ENCODING_ENABLED]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_128_130_ENCODING_ENABLED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_128_130_ENCODING_ENABLED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_128_130_ENCODING_ENABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_128_130_ENCODING_ENABLED]

//>> GET_[CONFIG0_128_130_ENCODING_ENABLED]
static inline bool GET_CONFIG0_128_130_ENCODING_ENABLED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.getBit<CONFIG0_128_130_ENCODING_ENABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CONFIG0_128_130_ENCODING_ENABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_128_130_ENCODING_ENABLED]

//>> SET_[CONFIG0_PHY_CNTR_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_PHY_CNTR_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_PHY_CNTR_LIMIT,
           CONFIG0_PHY_CNTR_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_PHY_CNTR_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_PHY_CNTR_LIMIT]

//>> SET_[CONFIG0_PHY_CNTR_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_PHY_CNTR_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_PHY_CNTR_LIMIT,
           CONFIG0_PHY_CNTR_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_PHY_CNTR_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_PHY_CNTR_LIMIT]

//>> GET_[CONFIG0_PHY_CNTR_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_PHY_CNTR_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_PHY_CNTR_LIMIT,
           CONFIG0_PHY_CNTR_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_PHY_CNTR_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_PHY_CNTR_LIMIT]

//>> SET_[CONFIG0_RUNLANE_OVRD_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_RUNLANE_OVRD_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_RUNLANE_OVRD_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_RUNLANE_OVRD_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_RUNLANE_OVRD_ENABLE]

//>> SET_[CONFIG0_RUNLANE_OVRD_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_RUNLANE_OVRD_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_RUNLANE_OVRD_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_RUNLANE_OVRD_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_RUNLANE_OVRD_ENABLE]

//>> SET_[CONFIG0_RUNLANE_OVRD_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_RUNLANE_OVRD_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.setBit<CONFIG0_RUNLANE_OVRD_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CONFIG0_RUNLANE_OVRD_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_RUNLANE_OVRD_ENABLE]

//>> CLEAR_[CONFIG0_RUNLANE_OVRD_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG0_RUNLANE_OVRD_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.clearBit<CONFIG0_RUNLANE_OVRD_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CONFIG0_RUNLANE_OVRD_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CONFIG0_RUNLANE_OVRD_ENABLE]

//>> GET_[CONFIG0_RUNLANE_OVRD_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_RUNLANE_OVRD_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_RUNLANE_OVRD_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_RUNLANE_OVRD_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_RUNLANE_OVRD_ENABLE]

//>> GET_[CONFIG0_RUNLANE_OVRD_ENABLE]
static inline bool GET_CONFIG0_RUNLANE_OVRD_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.getBit<CONFIG0_RUNLANE_OVRD_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CONFIG0_RUNLANE_OVRD_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_RUNLANE_OVRD_ENABLE]

//>> SET_[CONFIG0_PWRMGT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_PWRMGT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_PWRMGT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_PWRMGT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_PWRMGT_ENABLE]

//>> SET_[CONFIG0_PWRMGT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_PWRMGT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_PWRMGT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_PWRMGT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_PWRMGT_ENABLE]

//>> SET_[CONFIG0_PWRMGT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_PWRMGT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.setBit<CONFIG0_PWRMGT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CONFIG0_PWRMGT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_PWRMGT_ENABLE]

//>> CLEAR_[CONFIG0_PWRMGT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG0_PWRMGT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.clearBit<CONFIG0_PWRMGT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CONFIG0_PWRMGT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CONFIG0_PWRMGT_ENABLE]

//>> GET_[CONFIG0_PWRMGT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_PWRMGT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_PWRMGT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_PWRMGT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_PWRMGT_ENABLE]

//>> GET_[CONFIG0_PWRMGT_ENABLE]
static inline bool GET_CONFIG0_PWRMGT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.getBit<CONFIG0_PWRMGT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CONFIG0_PWRMGT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_PWRMGT_ENABLE]

//>> SET_[CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE]

//>> SET_[CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE]

//>> SET_[CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.setBit<CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE]

//>> CLEAR_[CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.clearBit<CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE]

//>> GET_[CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE]

//>> GET_[CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE]
static inline bool GET_CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.getBit<CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE]

//>> SET_[CONFIG0_HALF_WIDTH_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_HALF_WIDTH_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_HALF_WIDTH_BACKOFF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_HALF_WIDTH_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_HALF_WIDTH_BACKOFF_ENABLE]

//>> SET_[CONFIG0_HALF_WIDTH_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_HALF_WIDTH_BACKOFF_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_HALF_WIDTH_BACKOFF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_HALF_WIDTH_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_HALF_WIDTH_BACKOFF_ENABLE]

//>> SET_[CONFIG0_HALF_WIDTH_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_HALF_WIDTH_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.setBit<CONFIG0_HALF_WIDTH_BACKOFF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CONFIG0_HALF_WIDTH_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_HALF_WIDTH_BACKOFF_ENABLE]

//>> CLEAR_[CONFIG0_HALF_WIDTH_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG0_HALF_WIDTH_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.clearBit<CONFIG0_HALF_WIDTH_BACKOFF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CONFIG0_HALF_WIDTH_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CONFIG0_HALF_WIDTH_BACKOFF_ENABLE]

//>> GET_[CONFIG0_HALF_WIDTH_BACKOFF_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_HALF_WIDTH_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_HALF_WIDTH_BACKOFF_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_HALF_WIDTH_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_HALF_WIDTH_BACKOFF_ENABLE]

//>> GET_[CONFIG0_HALF_WIDTH_BACKOFF_ENABLE]
static inline bool GET_CONFIG0_HALF_WIDTH_BACKOFF_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.getBit<CONFIG0_HALF_WIDTH_BACKOFF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CONFIG0_HALF_WIDTH_BACKOFF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_HALF_WIDTH_BACKOFF_ENABLE]

//>> SET_[CONFIG0_SUPPORTED_MODES]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_SUPPORTED_MODES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_SUPPORTED_MODES,
           CONFIG0_SUPPORTED_MODES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_SUPPORTED_MODES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_SUPPORTED_MODES]

//>> SET_[CONFIG0_SUPPORTED_MODES]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_SUPPORTED_MODES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_SUPPORTED_MODES,
           CONFIG0_SUPPORTED_MODES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_SUPPORTED_MODES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_SUPPORTED_MODES]

//>> GET_[CONFIG0_SUPPORTED_MODES]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_SUPPORTED_MODES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_SUPPORTED_MODES,
           CONFIG0_SUPPORTED_MODES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_SUPPORTED_MODES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_SUPPORTED_MODES]

//>> SET_[CONFIG0_TRAIN_MODE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_TRAIN_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_TRAIN_MODE,
           CONFIG0_TRAIN_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_TRAIN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_TRAIN_MODE]

//>> SET_[CONFIG0_TRAIN_MODE]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_TRAIN_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_TRAIN_MODE,
           CONFIG0_TRAIN_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_TRAIN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_TRAIN_MODE]

//>> GET_[CONFIG0_TRAIN_MODE]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_TRAIN_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_TRAIN_MODE,
           CONFIG0_TRAIN_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_TRAIN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_TRAIN_MODE]

//>> SET_[CONFIG0_VERSION]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_VERSION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_VERSION,
           CONFIG0_VERSION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_VERSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_VERSION]

//>> SET_[CONFIG0_VERSION]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_VERSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_VERSION,
           CONFIG0_VERSION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_VERSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_VERSION]

//>> GET_[CONFIG0_VERSION]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_VERSION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_VERSION,
           CONFIG0_VERSION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_VERSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_VERSION]

//>> SET_[CONFIG0_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_RETRAIN]

//>> SET_[CONFIG0_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_RETRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_RETRAIN]

//>> SET_[CONFIG0_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.setBit<CONFIG0_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CONFIG0_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_RETRAIN]

//>> CLEAR_[CONFIG0_RETRAIN]
static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG0_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.clearBit<CONFIG0_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CONFIG0_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CONFIG0_RETRAIN]

//>> GET_[CONFIG0_RETRAIN]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_RETRAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_RETRAIN]

//>> GET_[CONFIG0_RETRAIN]
static inline bool GET_CONFIG0_RETRAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.getBit<CONFIG0_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CONFIG0_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_RETRAIN]

//>> SET_[CONFIG0_RESET]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access CONFIG0_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_RESET]

//>> SET_[CONFIG0_RESET]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.insertFromRight<CONFIG0_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access CONFIG0_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_RESET]

//>> SET_[CONFIG0_RESET]
static inline fapi2::buffer<uint64_t>& SET_CONFIG0_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.setBit<CONFIG0_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access CONFIG0_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CONFIG0_RESET]

//>> CLEAR_[CONFIG0_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_CONFIG0_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return o_data.clearBit<CONFIG0_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access CONFIG0_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CONFIG0_RESET]

//>> GET_[CONFIG0_RESET]
static inline fapi2::buffer<uint64_t>& GET_CONFIG0_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.extractToRight<CONFIG0_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access CONFIG0_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_RESET]

//>> GET_[CONFIG0_RESET]
static inline bool GET_CONFIG0_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CONFIG0));
#endif
    return i_data.getBit<CONFIG0_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access CONFIG0_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CONFIG0_RESET]

//>> PREP_[DLX_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLX_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
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
    FAPI_TRY(scomt::chkReg(DLX_CONFIG));
#endif
    return fapi2::putScom(i_target, DLX_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLX_CONFIG]


//>> SET_[DLX_CONFIG_CFG_DLX0]
static inline fapi2::buffer<uint64_t>& SET_DLX_CONFIG_CFG_DLX0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLX_CONFIG));
#endif
    return o_data.insertFromRight<DLX_CONFIG_CFG_DLX0,
           DLX_CONFIG_CFG_DLX0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access DLX_CONFIG_CFG_DLX0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLX_CONFIG_CFG_DLX0]

//>> SET_[DLX_CONFIG_CFG_DLX0]
static inline fapi2::buffer<uint64_t>& SET_DLX_CONFIG_CFG_DLX0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLX_CONFIG));
#endif
    return o_data.insertFromRight<DLX_CONFIG_CFG_DLX0,
           DLX_CONFIG_CFG_DLX0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access DLX_CONFIG_CFG_DLX0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLX_CONFIG_CFG_DLX0]

//>> GET_[DLX_CONFIG_CFG_DLX0]
static inline fapi2::buffer<uint64_t>& GET_DLX_CONFIG_CFG_DLX0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLX_CONFIG));
#endif
    return i_data.extractToRight<DLX_CONFIG_CFG_DLX0,
           DLX_CONFIG_CFG_DLX0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access DLX_CONFIG_CFG_DLX0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLX_CONFIG_CFG_DLX0]

//>> SET_[DLX_CONFIG_CFG_DLX1]
static inline fapi2::buffer<uint64_t>& SET_DLX_CONFIG_CFG_DLX1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLX_CONFIG));
#endif
    return o_data.insertFromRight<DLX_CONFIG_CFG_DLX1,
           DLX_CONFIG_CFG_DLX1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access DLX_CONFIG_CFG_DLX1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLX_CONFIG_CFG_DLX1]

//>> SET_[DLX_CONFIG_CFG_DLX1]
static inline fapi2::buffer<uint64_t>& SET_DLX_CONFIG_CFG_DLX1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLX_CONFIG));
#endif
    return o_data.insertFromRight<DLX_CONFIG_CFG_DLX1,
           DLX_CONFIG_CFG_DLX1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access DLX_CONFIG_CFG_DLX1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLX_CONFIG_CFG_DLX1]

//>> GET_[DLX_CONFIG_CFG_DLX1]
static inline fapi2::buffer<uint64_t>& GET_DLX_CONFIG_CFG_DLX1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLX_CONFIG));
#endif
    return i_data.extractToRight<DLX_CONFIG_CFG_DLX1,
           DLX_CONFIG_CFG_DLX1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access DLX_CONFIG_CFG_DLX1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLX_CONFIG_CFG_DLX1]

//>> PREP_[ERROR_ACTION]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ERROR_ACTION(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ERROR_ACTION;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[ERROR_ACTION]

//>> GET_[ERROR_ACTION]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ERROR_ACTION(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ERROR_ACTION;
#endif
    return fapi2::getScom(i_target, ERROR_ACTION, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[ERROR_ACTION]

//>> PUT_[ERROR_ACTION]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ERROR_ACTION(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return fapi2::putScom(i_target, ERROR_ACTION, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[ERROR_ACTION]


//>> SET_[ERROR_ACTION_11_ACTION]
static inline fapi2::buffer<uint64_t>& SET_ERROR_ACTION_11_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return o_data.insertFromRight<ERROR_ACTION_11_ACTION,
           ERROR_ACTION_11_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_ACTION_11_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_ACTION_11_ACTION]

//>> SET_[ERROR_ACTION_11_ACTION]
static inline fapi2::buffer<uint64_t>& SET_ERROR_ACTION_11_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return o_data.insertFromRight<ERROR_ACTION_11_ACTION,
           ERROR_ACTION_11_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_ACTION_11_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_ACTION_11_ACTION]

//>> GET_[ERROR_ACTION_11_ACTION]
static inline fapi2::buffer<uint64_t>& GET_ERROR_ACTION_11_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return i_data.extractToRight<ERROR_ACTION_11_ACTION,
           ERROR_ACTION_11_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_ACTION_11_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_ACTION_11_ACTION]

//>> SET_[ERROR_ACTION_10_ACTION]
static inline fapi2::buffer<uint64_t>& SET_ERROR_ACTION_10_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return o_data.insertFromRight<ERROR_ACTION_10_ACTION,
           ERROR_ACTION_10_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_ACTION_10_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_ACTION_10_ACTION]

//>> SET_[ERROR_ACTION_10_ACTION]
static inline fapi2::buffer<uint64_t>& SET_ERROR_ACTION_10_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return o_data.insertFromRight<ERROR_ACTION_10_ACTION,
           ERROR_ACTION_10_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_ACTION_10_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_ACTION_10_ACTION]

//>> GET_[ERROR_ACTION_10_ACTION]
static inline fapi2::buffer<uint64_t>& GET_ERROR_ACTION_10_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return i_data.extractToRight<ERROR_ACTION_10_ACTION,
           ERROR_ACTION_10_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_ACTION_10_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_ACTION_10_ACTION]

//>> SET_[ERROR_ACTION_9_ACTION]
static inline fapi2::buffer<uint64_t>& SET_ERROR_ACTION_9_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return o_data.insertFromRight<ERROR_ACTION_9_ACTION,
           ERROR_ACTION_9_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_ACTION_9_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_ACTION_9_ACTION]

//>> SET_[ERROR_ACTION_9_ACTION]
static inline fapi2::buffer<uint64_t>& SET_ERROR_ACTION_9_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return o_data.insertFromRight<ERROR_ACTION_9_ACTION,
           ERROR_ACTION_9_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_ACTION_9_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_ACTION_9_ACTION]

//>> GET_[ERROR_ACTION_9_ACTION]
static inline fapi2::buffer<uint64_t>& GET_ERROR_ACTION_9_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return i_data.extractToRight<ERROR_ACTION_9_ACTION,
           ERROR_ACTION_9_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_ACTION_9_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_ACTION_9_ACTION]

//>> SET_[ERROR_ACTION_8_ACTION]
static inline fapi2::buffer<uint64_t>& SET_ERROR_ACTION_8_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return o_data.insertFromRight<ERROR_ACTION_8_ACTION,
           ERROR_ACTION_8_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_ACTION_8_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_ACTION_8_ACTION]

//>> SET_[ERROR_ACTION_8_ACTION]
static inline fapi2::buffer<uint64_t>& SET_ERROR_ACTION_8_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return o_data.insertFromRight<ERROR_ACTION_8_ACTION,
           ERROR_ACTION_8_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_ACTION_8_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_ACTION_8_ACTION]

//>> GET_[ERROR_ACTION_8_ACTION]
static inline fapi2::buffer<uint64_t>& GET_ERROR_ACTION_8_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return i_data.extractToRight<ERROR_ACTION_8_ACTION,
           ERROR_ACTION_8_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_ACTION_8_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_ACTION_8_ACTION]

//>> SET_[ERROR_ACTION_7_ACTION]
static inline fapi2::buffer<uint64_t>& SET_ERROR_ACTION_7_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return o_data.insertFromRight<ERROR_ACTION_7_ACTION,
           ERROR_ACTION_7_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_ACTION_7_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_ACTION_7_ACTION]

//>> SET_[ERROR_ACTION_7_ACTION]
static inline fapi2::buffer<uint64_t>& SET_ERROR_ACTION_7_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return o_data.insertFromRight<ERROR_ACTION_7_ACTION,
           ERROR_ACTION_7_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_ACTION_7_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_ACTION_7_ACTION]

//>> GET_[ERROR_ACTION_7_ACTION]
static inline fapi2::buffer<uint64_t>& GET_ERROR_ACTION_7_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return i_data.extractToRight<ERROR_ACTION_7_ACTION,
           ERROR_ACTION_7_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_ACTION_7_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_ACTION_7_ACTION]

//>> SET_[ERROR_ACTION_6_ACTION]
static inline fapi2::buffer<uint64_t>& SET_ERROR_ACTION_6_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return o_data.insertFromRight<ERROR_ACTION_6_ACTION,
           ERROR_ACTION_6_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_ACTION_6_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_ACTION_6_ACTION]

//>> SET_[ERROR_ACTION_6_ACTION]
static inline fapi2::buffer<uint64_t>& SET_ERROR_ACTION_6_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return o_data.insertFromRight<ERROR_ACTION_6_ACTION,
           ERROR_ACTION_6_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_ACTION_6_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_ACTION_6_ACTION]

//>> GET_[ERROR_ACTION_6_ACTION]
static inline fapi2::buffer<uint64_t>& GET_ERROR_ACTION_6_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return i_data.extractToRight<ERROR_ACTION_6_ACTION,
           ERROR_ACTION_6_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_ACTION_6_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_ACTION_6_ACTION]

//>> SET_[ERROR_ACTION_5_ACTION]
static inline fapi2::buffer<uint64_t>& SET_ERROR_ACTION_5_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return o_data.insertFromRight<ERROR_ACTION_5_ACTION,
           ERROR_ACTION_5_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_ACTION_5_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_ACTION_5_ACTION]

//>> SET_[ERROR_ACTION_5_ACTION]
static inline fapi2::buffer<uint64_t>& SET_ERROR_ACTION_5_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return o_data.insertFromRight<ERROR_ACTION_5_ACTION,
           ERROR_ACTION_5_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_ACTION_5_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_ACTION_5_ACTION]

//>> GET_[ERROR_ACTION_5_ACTION]
static inline fapi2::buffer<uint64_t>& GET_ERROR_ACTION_5_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return i_data.extractToRight<ERROR_ACTION_5_ACTION,
           ERROR_ACTION_5_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_ACTION_5_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_ACTION_5_ACTION]

//>> SET_[ERROR_ACTION_4_ACTION]
static inline fapi2::buffer<uint64_t>& SET_ERROR_ACTION_4_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return o_data.insertFromRight<ERROR_ACTION_4_ACTION,
           ERROR_ACTION_4_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_ACTION_4_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_ACTION_4_ACTION]

//>> SET_[ERROR_ACTION_4_ACTION]
static inline fapi2::buffer<uint64_t>& SET_ERROR_ACTION_4_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return o_data.insertFromRight<ERROR_ACTION_4_ACTION,
           ERROR_ACTION_4_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_ACTION_4_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_ACTION_4_ACTION]

//>> GET_[ERROR_ACTION_4_ACTION]
static inline fapi2::buffer<uint64_t>& GET_ERROR_ACTION_4_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return i_data.extractToRight<ERROR_ACTION_4_ACTION,
           ERROR_ACTION_4_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_ACTION_4_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_ACTION_4_ACTION]

//>> SET_[ERROR_ACTION_3_ACTION]
static inline fapi2::buffer<uint64_t>& SET_ERROR_ACTION_3_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return o_data.insertFromRight<ERROR_ACTION_3_ACTION,
           ERROR_ACTION_3_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_ACTION_3_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_ACTION_3_ACTION]

//>> SET_[ERROR_ACTION_3_ACTION]
static inline fapi2::buffer<uint64_t>& SET_ERROR_ACTION_3_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return o_data.insertFromRight<ERROR_ACTION_3_ACTION,
           ERROR_ACTION_3_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_ACTION_3_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_ACTION_3_ACTION]

//>> GET_[ERROR_ACTION_3_ACTION]
static inline fapi2::buffer<uint64_t>& GET_ERROR_ACTION_3_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return i_data.extractToRight<ERROR_ACTION_3_ACTION,
           ERROR_ACTION_3_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_ACTION_3_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_ACTION_3_ACTION]

//>> SET_[ERROR_ACTION_2_ACTION]
static inline fapi2::buffer<uint64_t>& SET_ERROR_ACTION_2_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return o_data.insertFromRight<ERROR_ACTION_2_ACTION,
           ERROR_ACTION_2_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_ACTION_2_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_ACTION_2_ACTION]

//>> SET_[ERROR_ACTION_2_ACTION]
static inline fapi2::buffer<uint64_t>& SET_ERROR_ACTION_2_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return o_data.insertFromRight<ERROR_ACTION_2_ACTION,
           ERROR_ACTION_2_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_ACTION_2_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_ACTION_2_ACTION]

//>> GET_[ERROR_ACTION_2_ACTION]
static inline fapi2::buffer<uint64_t>& GET_ERROR_ACTION_2_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return i_data.extractToRight<ERROR_ACTION_2_ACTION,
           ERROR_ACTION_2_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_ACTION_2_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_ACTION_2_ACTION]

//>> SET_[ERROR_ACTION_1_ACTION]
static inline fapi2::buffer<uint64_t>& SET_ERROR_ACTION_1_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return o_data.insertFromRight<ERROR_ACTION_1_ACTION,
           ERROR_ACTION_1_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_ACTION_1_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_ACTION_1_ACTION]

//>> SET_[ERROR_ACTION_1_ACTION]
static inline fapi2::buffer<uint64_t>& SET_ERROR_ACTION_1_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return o_data.insertFromRight<ERROR_ACTION_1_ACTION,
           ERROR_ACTION_1_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_ACTION_1_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_ACTION_1_ACTION]

//>> GET_[ERROR_ACTION_1_ACTION]
static inline fapi2::buffer<uint64_t>& GET_ERROR_ACTION_1_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return i_data.extractToRight<ERROR_ACTION_1_ACTION,
           ERROR_ACTION_1_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_ACTION_1_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_ACTION_1_ACTION]

//>> SET_[ERROR_ACTION_0_ACTION]
static inline fapi2::buffer<uint64_t>& SET_ERROR_ACTION_0_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return o_data.insertFromRight<ERROR_ACTION_0_ACTION,
           ERROR_ACTION_0_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access ERROR_ACTION_0_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_ACTION_0_ACTION]

//>> SET_[ERROR_ACTION_0_ACTION]
static inline fapi2::buffer<uint64_t>& SET_ERROR_ACTION_0_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return o_data.insertFromRight<ERROR_ACTION_0_ACTION,
           ERROR_ACTION_0_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access ERROR_ACTION_0_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_ACTION_0_ACTION]

//>> GET_[ERROR_ACTION_0_ACTION]
static inline fapi2::buffer<uint64_t>& GET_ERROR_ACTION_0_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_ACTION));
#endif
    return i_data.extractToRight<ERROR_ACTION_0_ACTION,
           ERROR_ACTION_0_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access ERROR_ACTION_0_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_ACTION_0_ACTION]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
