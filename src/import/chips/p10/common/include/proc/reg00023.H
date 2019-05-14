/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00023.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

#ifndef __PROC_REG00023_H_
#define __PROC_REG00023_H_

namespace scomt
{
namespace proc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_EPS_FIR_MODE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_EPS_FIR_MODE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_EPS_FIR_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_EPS_FIR_MODE_REG;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_EPS_FIR_MODE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_EPS_FIR_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_EPS_FIR_MODE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_RECOV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_RECOV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_RECOV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_RECOV(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_RECOV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_RECOV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_RECOV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_SPATTN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_SPATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_SPATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_SPATTN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_LXSTOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_LXSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_LXSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_LXSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_LXSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_LXSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_LXSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_LXSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_LXSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_LXSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_LXSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_LXSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_LXSTOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_LXSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_LXSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_LXSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_LXSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_LXSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_HOSTATTN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_HOSTATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_HOSTATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_HOSTATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_HOSTATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_HOSTATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_HOSTATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_HOSTATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_HOSTATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_HOSTATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_HOSTATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_HOSTATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_HOSTATTN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_HOSTATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_HOSTATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_HOSTATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_HOSTATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_XSTOP_LOCK_HOSTATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_DISABLE_IOPB_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_DISABLE_IOPB_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_DISABLE_IOPB_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_DISABLE_IOPB_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_DISABLE_IOPB_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_DISABLE_IOPB_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_DISABLE_IOPB_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_DISABLE_IOPB_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_DISABLE_IOPB_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_DISABLE_IOPB_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_DISABLE_IOPB_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_DISABLE_IOPB_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_DISABLE_IOPB_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_DISABLE_IOPB_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_DISABLE_IOPB_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_DISABLE_IOPB_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_DISABLE_IOPB_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_DISABLE_IOPB_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MASK_DIRECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MASK_DIRECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MASK_DIRECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MASK_DIRECT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MASK_DIRECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MASK_DIRECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MASK_DIRECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MASK_DIRECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MASK_DIRECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_MASK_DIRECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MASK_DIRECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MASK_DIRECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_MASK_DIRECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MASK_DIRECT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MASK_DIRECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_MASK_DIRECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MASK_DIRECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MASK_DIRECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_FIR_MODE_REG_MODE_REG15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_OPCG_ALIGN(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_OPCG_ALIGN;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_OPCG_ALIGN(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_OPCG_ALIGN;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_OPCG_ALIGN, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_OPCG_ALIGN(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_OPCG_ALIGN, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN,
           TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN,
           TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN,
           TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_INOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN,
           TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN,
           TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN,
           TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SNOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN,
           TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN,
           TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN,
           TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ENOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT,
           TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT,
           TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT,
           TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_INOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT,
           TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT,
           TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT,
           TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SNOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT,
           TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT,
           TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT,
           TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ENOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.setBit<TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.clearBit<TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.getBit<TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.setBit<TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.clearBit<TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.getBit<TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.setBit<TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.clearBit<TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.getBit<TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.setBit<TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.clearBit<TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.getBit<TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT,
           TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT,
           TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT,
           TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_ALIGN_SOURCE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO,
           TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO,
           TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO,
           TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_SCAN_RATIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES,
           TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES,
           TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_OPCG_ALIGN));
#endif
    return i_data.extractToRight<TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES,
           TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_OPCG_ALIGN_OPCG_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_PHASE_COUNTER_RESET(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_PHASE_COUNTER_RESET;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_PHASE_COUNTER_RESET(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_PHASE_COUNTER_RESET;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_PHASE_COUNTER_RESET, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_PHASE_COUNTER_RESET(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_PHASE_COUNTER_RESET));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_PHASE_COUNTER_RESET, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_PHASE_COUNTER_RESET));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_PHASE_COUNTER_RESET));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_PHASE_COUNTER_RESET));
#endif
    return o_data.setBit<TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_PHASE_COUNTER_RESET));
#endif
    return o_data.clearBit<TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_PHASE_COUNTER_RESET));
#endif
    return i_data.extractToRight<TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_PHASE_COUNTER_RESET));
#endif
    return i_data.getBit<TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_PHASE_COUNTER_RESET_PHASECOUNTER_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_SCAN64CONTSCAN(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_SCAN64CONTSCAN;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_SCAN64CONTSCAN(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_SCAN64CONTSCAN;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_SCAN64CONTSCAN, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_SCAN64CONTSCAN(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_SCAN64CONTSCAN));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_SCAN64CONTSCAN, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA0_TR1_CONFIG_4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA0_TR1_CONFIG_4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA0_TR1_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA0_TR1_CONFIG_4;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA0_TR1_CONFIG_4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA0_TR1_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA0_TR1_CONFIG_4));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA0_TR1_CONFIG_4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA0_TR1_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA0_TR1_CONFIG_4));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA0_TR1_CONFIG_4_A,
           TP_TCN1_N1_TRA0_TR1_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA0_TR1_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA0_TR1_CONFIG_4_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA0_TR1_CONFIG_4));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA0_TR1_CONFIG_4_A,
           TP_TCN1_N1_TRA0_TR1_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA0_TR1_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA0_TR1_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA0_TR1_CONFIG_4));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA0_TR1_CONFIG_4_A,
           TP_TCN1_N1_TRA0_TR1_CONFIG_4_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA0_TR1_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA0_TR1_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA0_TR1_CONFIG_4));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA0_TR1_CONFIG_4_B,
           TP_TCN1_N1_TRA0_TR1_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA0_TR1_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA0_TR1_CONFIG_4_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA0_TR1_CONFIG_4));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA0_TR1_CONFIG_4_B,
           TP_TCN1_N1_TRA0_TR1_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA0_TR1_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA0_TR1_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA0_TR1_CONFIG_4));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA0_TR1_CONFIG_4_B,
           TP_TCN1_N1_TRA0_TR1_CONFIG_4_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA0_TR1_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA1_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA1_TR0_CONFIG_2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA1_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA1_TR0_CONFIG_2;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA1_TR0_CONFIG_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA1_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR0_CONFIG_2));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA1_TR0_CONFIG_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR0_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR0_CONFIG_2_A,
           TP_TCN1_N1_TRA1_TR0_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR0_CONFIG_2_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR0_CONFIG_2_A,
           TP_TCN1_N1_TRA1_TR0_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA1_TR0_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR0_CONFIG_2));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA1_TR0_CONFIG_2_A,
           TP_TCN1_N1_TRA1_TR0_CONFIG_2_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR0_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR0_CONFIG_2_B,
           TP_TCN1_N1_TRA1_TR0_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR0_CONFIG_2_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR0_CONFIG_2_B,
           TP_TCN1_N1_TRA1_TR0_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA1_TR0_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR0_CONFIG_2));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA1_TR0_CONFIG_2_B,
           TP_TCN1_N1_TRA1_TR0_CONFIG_2_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA2_TR0_CONFIG_5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA2_TR0_CONFIG_5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA2_TR0_CONFIG_5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA2_TR0_CONFIG_5;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA2_TR0_CONFIG_5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA2_TR0_CONFIG_5(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_CONFIG_5));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA2_TR0_CONFIG_5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA2_TR0_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA2_TR0_CONFIG_5_C,
           TP_TCN1_N1_TRA2_TR0_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA2_TR0_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA2_TR0_CONFIG_5_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA2_TR0_CONFIG_5_C,
           TP_TCN1_N1_TRA2_TR0_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA2_TR0_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA2_TR0_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_CONFIG_5));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA2_TR0_CONFIG_5_C,
           TP_TCN1_N1_TRA2_TR0_CONFIG_5_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA2_TR0_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA2_TR0_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA2_TR0_CONFIG_5_D,
           TP_TCN1_N1_TRA2_TR0_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA2_TR0_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA2_TR0_CONFIG_5_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA2_TR0_CONFIG_5_D,
           TP_TCN1_N1_TRA2_TR0_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA2_TR0_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA2_TR0_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_CONFIG_5));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA2_TR0_CONFIG_5_D,
           TP_TCN1_N1_TRA2_TR0_CONFIG_5_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA2_TR0_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA3_TR1_CONFIG_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA3_TR1_CONFIG_3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA3_TR1_CONFIG_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA3_TR1_CONFIG_3;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA3_TR1_CONFIG_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA3_TR1_CONFIG_3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA3_TR1_CONFIG_3));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA3_TR1_CONFIG_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA3_TR1_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA3_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA3_TR1_CONFIG_3_C,
           TP_TCN1_N1_TRA3_TR1_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA3_TR1_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA3_TR1_CONFIG_3_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA3_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA3_TR1_CONFIG_3_C,
           TP_TCN1_N1_TRA3_TR1_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA3_TR1_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA3_TR1_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA3_TR1_CONFIG_3));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA3_TR1_CONFIG_3_C,
           TP_TCN1_N1_TRA3_TR1_CONFIG_3_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA3_TR1_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA3_TR1_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA3_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA3_TR1_CONFIG_3_D,
           TP_TCN1_N1_TRA3_TR1_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA3_TR1_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA3_TR1_CONFIG_3_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA3_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA3_TR1_CONFIG_3_D,
           TP_TCN1_N1_TRA3_TR1_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA3_TR1_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA3_TR1_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA3_TR1_CONFIG_3));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA3_TR1_CONFIG_3_D,
           TP_TCN1_N1_TRA3_TR1_CONFIG_3_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA3_TR1_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA4_TR1_CONFIG_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA4_TR1_CONFIG_2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA4_TR1_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA4_TR1_CONFIG_2;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA4_TR1_CONFIG_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA4_TR1_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA4_TR1_CONFIG_2));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA4_TR1_CONFIG_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA4_TR1_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA4_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA4_TR1_CONFIG_2_A,
           TP_TCN1_N1_TRA4_TR1_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA4_TR1_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA4_TR1_CONFIG_2_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA4_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA4_TR1_CONFIG_2_A,
           TP_TCN1_N1_TRA4_TR1_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA4_TR1_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA4_TR1_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA4_TR1_CONFIG_2));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA4_TR1_CONFIG_2_A,
           TP_TCN1_N1_TRA4_TR1_CONFIG_2_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA4_TR1_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA4_TR1_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA4_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA4_TR1_CONFIG_2_B,
           TP_TCN1_N1_TRA4_TR1_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA4_TR1_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA4_TR1_CONFIG_2_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA4_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA4_TR1_CONFIG_2_B,
           TP_TCN1_N1_TRA4_TR1_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA4_TR1_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA4_TR1_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA4_TR1_CONFIG_2));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA4_TR1_CONFIG_2_B,
           TP_TCN1_N1_TRA4_TR1_CONFIG_2_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA4_TR1_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA5_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA5_TR0_CONFIG_4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA5_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA5_TR0_CONFIG_4;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA5_TR0_CONFIG_4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA5_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR0_CONFIG_4));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA5_TR0_CONFIG_4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA5_TR0_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA5_TR0_CONFIG_4_A,
           TP_TCN1_N1_TRA5_TR0_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA5_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA5_TR0_CONFIG_4_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA5_TR0_CONFIG_4_A,
           TP_TCN1_N1_TRA5_TR0_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA5_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA5_TR0_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR0_CONFIG_4));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA5_TR0_CONFIG_4_A,
           TP_TCN1_N1_TRA5_TR0_CONFIG_4_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA5_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA5_TR0_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA5_TR0_CONFIG_4_B,
           TP_TCN1_N1_TRA5_TR0_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA5_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA5_TR0_CONFIG_4_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA5_TR0_CONFIG_4_B,
           TP_TCN1_N1_TRA5_TR0_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA5_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA5_TR0_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR0_CONFIG_4));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA5_TR0_CONFIG_4_B,
           TP_TCN1_N1_TRA5_TR0_CONFIG_4_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA5_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA,
           TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA,
           TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA,
           TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS,
           TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS,
           TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS,
           TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA6_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA6_TR0_CONFIG_3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA6_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA6_TR0_CONFIG_3;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA6_TR0_CONFIG_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA6_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_CONFIG_3));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA6_TR0_CONFIG_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_CONFIG_3_C,
           TP_TCN1_N1_TRA6_TR0_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_CONFIG_3_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_CONFIG_3_C,
           TP_TCN1_N1_TRA6_TR0_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA6_TR0_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_CONFIG_3));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA6_TR0_CONFIG_3_C,
           TP_TCN1_N1_TRA6_TR0_CONFIG_3_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_CONFIG_3_D,
           TP_TCN1_N1_TRA6_TR0_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_CONFIG_3_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_CONFIG_3_D,
           TP_TCN1_N1_TRA6_TR0_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA6_TR0_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_CONFIG_3));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA6_TR0_CONFIG_3_D,
           TP_TCN1_N1_TRA6_TR0_CONFIG_3_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_XSTOP_MASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_XSTOP_MASK_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_XSTOP_MASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_XSTOP_MASK_RW;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_XSTOP_MASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_XSTOP_MASK_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_XSTOP_MASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_XSTOP_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_XSTOP_MASK_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_XSTOP_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_XSTOP_MASK_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_XSTOP_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_XSTOP_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_XSTOP_MASK_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_XSTOP_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_XSTOP_MASK_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_XSTOP_MASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_XSTOP_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_XSTOP_MASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_XSTOP_MASK_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_XSTOP_MASK_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_XSTOP_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_XSTOP_MASK_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_XSTOP_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_XSTOP_MASK_53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_XSTOP_MASK_53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_XSTOP_MASK_53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_XSTOP_MASK_RW, TP_TCN1_N1_XSTOP_MASK_WO_CLEAR, TP_TCN1_N1_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_XSTOP_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_AD_TOD_DATA_RCV_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_TOD_DATA_RCV_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_AD_TOD_DATA_RCV_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_TOD_DATA_RCV_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_AD_TOD_DATA_RCV_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_AD_TOD_DATA_RCV_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOD_DATA_RCV_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_AD_TOD_DATA_RCV_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOD_DATA_RCV_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV,
           TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOD_DATA_RCV_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV,
           TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOD_DATA_RCV_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV,
           TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_TOD_DATA_RCV_REG_PCB_TOD_DATA_RCV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_BCDE_CTL_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCDE_CTL_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_BCDE_CTL_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCDE_CTL_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_BCDE_CTL_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_BCDE_CTL_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL_OCI, TP_TPBR_PBA_PBAO_BCDE_CTL_PIB));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_BCDE_CTL_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_BCDE_CTL_PIB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCDE_CTL_PIB;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_BCDE_CTL_PIB(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCDE_CTL_PIB;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_BCDE_CTL_PIB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_BCDE_CTL_PIB(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL_OCI, TP_TPBR_PBA_PBAO_BCDE_CTL_PIB));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_BCDE_CTL_PIB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_CTL_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL_OCI, TP_TPBR_PBA_PBAO_BCDE_CTL_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_CTL_OP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_CTL_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL_OCI, TP_TPBR_PBA_PBAO_BCDE_CTL_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_CTL_OP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_CTL_OP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL_OCI, TP_TPBR_PBA_PBAO_BCDE_CTL_PIB));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_BCDE_CTL_OP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_BCDE_CTL_OP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL_OCI, TP_TPBR_PBA_PBAO_BCDE_CTL_PIB));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_BCDE_CTL_OP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCDE_CTL_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL_OCI, TP_TPBR_PBA_PBAO_BCDE_CTL_PIB));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCDE_CTL_OP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_BCDE_CTL_OP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL_OCI, TP_TPBR_PBA_PBAO_BCDE_CTL_PIB));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_BCDE_CTL_OP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_CTL_ART(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL_OCI, TP_TPBR_PBA_PBAO_BCDE_CTL_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_CTL_ART,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_ART chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_CTL_ART(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL_OCI, TP_TPBR_PBA_PBAO_BCDE_CTL_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_CTL_ART,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_ART chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_CTL_ART(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL_OCI, TP_TPBR_PBA_PBAO_BCDE_CTL_PIB));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_BCDE_CTL_ART>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_ART chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_BCDE_CTL_ART(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL_OCI, TP_TPBR_PBA_PBAO_BCDE_CTL_PIB));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_BCDE_CTL_ART>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_ART chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCDE_CTL_ART(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL_OCI, TP_TPBR_PBA_PBAO_BCDE_CTL_PIB));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCDE_CTL_ART,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_ART chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_BCDE_CTL_ART(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL_OCI, TP_TPBR_PBA_PBAO_BCDE_CTL_PIB));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_BCDE_CTL_ART>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_ART chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBABAR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBABAR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBABAR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBABAR0;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBABAR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBABAR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBABAR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE,
           TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE,
           TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE,
           TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_ADDR,
           TP_TPBR_PBA_PBAO_PBABAR0_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_ADDR,
           TP_TPBR_PBA_PBAO_PBABAR0_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABAR0_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABAR0_ADDR,
           TP_TPBR_PBA_PBAO_PBABAR0_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_VTARGET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_VTARGET,
           TP_TPBR_PBA_PBAO_PBABAR0_VTARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_VTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_VTARGET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_VTARGET,
           TP_TPBR_PBA_PBAO_PBABAR0_VTARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_VTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABAR0_VTARGET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABAR0_VTARGET,
           TP_TPBR_PBA_PBAO_PBABAR0_VTARGET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_VTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBABARMSK1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBABARMSK1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBABARMSK1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBABARMSK1;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBABARMSK1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBABARMSK1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABARMSK1));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBABARMSK1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABARMSK1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK,
           TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABARMSK1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK,
           TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABARMSK1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK,
           TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBARBUFVAL0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBARBUFVAL0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBARBUFVAL0;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBARBUFVAL0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBARBUFVAL0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBARBUFVAL0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAXISHBR1_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXISHBR1_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAXISHBR1_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXISHBR1_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAXISHBR1_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAXISHBR1_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHBR1_OCI, TP_TPBR_PBA_PBAO_PBAXISHBR1_PIB));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAXISHBR1_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAXISHBR1_PIB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXISHBR1_PIB;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAXISHBR1_PIB(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXISHBR1_PIB;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAXISHBR1_PIB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAXISHBR1_PIB(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHBR1_OCI, TP_TPBR_PBA_PBAO_PBAXISHBR1_PIB));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAXISHBR1_PIB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHBR1_OCI, TP_TPBR_PBA_PBAO_PBAXISHBR1_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START,
           TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHBR1_OCI, TP_TPBR_PBA_PBAO_PBAXISHBR1_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START,
           TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHBR1_OCI, TP_TPBR_PBA_PBAO_PBAXISHBR1_PIB));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START,
           TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHBR1_PBAXISHBR1_PUSH_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR,
           TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXISHCS0_PIB));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAXSHBR1_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXSHBR1_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAXSHBR1_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXSHBR1_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAXSHBR1_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAXSHBR1_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHBR1_OCI, TP_TPBR_PBA_PBAO_PBAXSHBR1_PIB));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAXSHBR1_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAXSHBR1_PIB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXSHBR1_PIB;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAXSHBR1_PIB(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXSHBR1_PIB;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAXSHBR1_PIB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAXSHBR1_PIB(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHBR1_OCI, TP_TPBR_PBA_PBAO_PBAXSHBR1_PIB));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAXSHBR1_PIB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0_OCI, TP_TPBR_PBA_PBAO_PBAXSHCS0_PIB));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_CH_MISC_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_CH_MISC_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSI_WRAP_RX_CH_MISC_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSI_WRAP_RX_CH_MISC_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSI_WRAP_TX_TO_RT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_TX_TO_RT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSI_WRAP_TX_TO_RT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_TX_TO_RT_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSI_WRAP_TX_TO_RT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSI_WRAP_TX_TO_RT_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_TO_RT_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSI_WRAP_TX_TO_RT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_TO_RT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE,
           TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_TO_RT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE,
           TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_TO_RT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE,
           TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_TO_RT_REG_TIMEOUT_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_TO_RT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE,
           TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_TO_RT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE,
           TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_TO_RT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE,
           TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_TO_RT_REG_RETRY_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSIHB_NOTRUST_BAR0MASK(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_NOTRUST_BAR0MASK;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSIHB_NOTRUST_BAR0MASK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_NOTRUST_BAR0MASK;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSIHB_NOTRUST_BAR0MASK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSIHB_NOTRUST_BAR0MASK(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR0MASK));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSIHB_NOTRUST_BAR0MASK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR0MASK));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK,
           TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR0MASK));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK,
           TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR0MASK));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK,
           TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_NOTRUST_BAR0MASK_UNTRUSTED_BAR0MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSIHB_NOTRUST_BAR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_NOTRUST_BAR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSIHB_NOTRUST_BAR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_NOTRUST_BAR1;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSIHB_NOTRUST_BAR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSIHB_NOTRUST_BAR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR1));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSIHB_NOTRUST_BAR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR1));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1,
           TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR1));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1,
           TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR1));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1,
           TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_NOTRUST_BAR1_UNTRUSTED_BAR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSIHB_NOTRUST_BAR1MASK(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_NOTRUST_BAR1MASK;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSIHB_NOTRUST_BAR1MASK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_NOTRUST_BAR1MASK;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSIHB_NOTRUST_BAR1MASK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSIHB_NOTRUST_BAR1MASK(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR1MASK));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSIHB_NOTRUST_BAR1MASK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR1MASK));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK,
           TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR1MASK));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK,
           TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR1MASK));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK,
           TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_NOTRUST_BAR1MASK_UNTRUSTED_BAR1MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR,
           TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR,
           TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR,
           TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR,
           TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR,
           TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR,
           TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP,
           TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP,
           TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP,
           TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_2_MULTICAST2_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN0_RECOV_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_RECOV_INTERRUPT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN0_RECOV_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_RECOV_INTERRUPT_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN0_RECOV_INTERRUPT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN0_RECOV_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_RECOV_INTERRUPT_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN0_RECOV_INTERRUPT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN1_PLL_LOCK_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_PLL_LOCK_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN1_PLL_LOCK_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_PLL_LOCK_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN1_PLL_LOCK_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN1_PLL_LOCK_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_PLL_LOCK_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN1_PLL_LOCK_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_HANG_PULSE_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_HANG_PULSE_REG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_HANG_PULSE_REG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_HANG_PULSE_REG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_HANG_PULSE_REG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_HANG_PULSE_REG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6,
           TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_HANG_PULSE_REG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HANG_PULSE_6_REG_SUPPRESS_HANG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP,
           TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP,
           TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP,
           TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_2_MULTICAST2_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_DCC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_DCC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_DCC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_DCC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_DCC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_DCC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_DCC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_DCC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCC_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_PDLY_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_PDLY_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_PDLY_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_PDLY_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_PDLY_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_PDLY_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_PDLY_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_PDLY_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_PDLY_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_PDLY_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_PDLY_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_PDLY_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_PDLY_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_PDLY_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_PDLY_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_PDLY_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_PDLY_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_SKEWADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_SKEWADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_SKEWADJUST_RESET_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_SKEWADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_SKEWADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_SKEWADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_SKEWADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_SKEWADJUST_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE0_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_SKEWADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_SKEWADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_SKEWADJUST_RESET_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_SKEWADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_SKEWADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_SKEWADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_SKEWADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_SKEWADJUST_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE1_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_SKEWADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_SKEWADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_SKEWADJUST_RESET_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_SKEWADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_SKEWADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_SKEWADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_SKEWADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_SKEWADJUST_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE2_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_SKEWADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_SKEWADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_SKEWADJUST_RESET_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_SKEWADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_SKEWADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_SKEWADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_SKEWADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_SKEWADJUST_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ACHE3_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCADJUST_RESET_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCADJUST_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE0_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCADJUST_RESET_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCADJUST_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE1_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCADJUST_RESET_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCADJUST_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE2_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCADJUST_RESET_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCADJUST_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCADJUST_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL1_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL1_ORE3_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_PLL_LOCK_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_PLL_LOCK_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_PLL_LOCK_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_PLL_LOCK_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_PLL_LOCK_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_PLL_LOCK_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_PLL_LOCK_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_PLL_LOCK_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_RW));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_RW));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_RW));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_RW));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_RW));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SCOM));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SCOM(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SCOM;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SCOM(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SCOM;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SCOM, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SCOM(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SCOM));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SCOM, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_R_NW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RSP_INFO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_RO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBL_DATAOP_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCI;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_RO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCB_OCI_GPEXISIB_PIB_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCB_OCI_GPEXISIB_PIB_ADDR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCB_OCI_GPEXISIB_PIB_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCB_OCI_GPEXISIB_PIB_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCB_OCI_GPEXISIB_PIB_ADDR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_RO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCB_OCI_GPEXISIB_PIB_ADDR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCB_OCI_GPEXISIB_PIB_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCB_OCI_GPEXISIB_PIB_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCB_OCI_GPEXISIB_PIB_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCI, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_RO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCB_OCI_GPEXISIB_PIB_ADDR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCB_OCI_GPEXISIB_PIB_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISIBU_OCB_OCI_GPEXISIB_PIB_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
