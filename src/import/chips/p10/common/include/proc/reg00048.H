/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00048.H $         */
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

#ifndef __PROC_REG00048_H_
#define __PROC_REG00048_H_

namespace scomt
{
namespace proc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN0_ATTN_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_ATTN_INTERRUPT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN0_ATTN_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_ATTN_INTERRUPT_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN0_ATTN_INTERRUPT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN0_ATTN_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ATTN_INTERRUPT_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN0_ATTN_INTERRUPT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN0_HOSTATTN_INTERRUPT_REG(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_HOSTATTN_INTERRUPT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN0_HOSTATTN_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_HOSTATTN_INTERRUPT_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN0_HOSTATTN_INTERRUPT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN0_HOSTATTN_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HOSTATTN_INTERRUPT_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN0_HOSTATTN_INTERRUPT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_MUX_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_MUX_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_MUX_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_MUX_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_MUX_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_MUX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_MUX_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_MUX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_MUX_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_MUX_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_MUX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PLL_ERRS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PLL_ERRS,
           TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PLL_ERRS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PLL_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PLL_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PLL_ERRS,
           TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PLL_ERRS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PLL_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PLL_ERRS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PLL_ERRS,
           TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PLL_ERRS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_MASK_PLL_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_QME_PAR_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_QME_PAR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_QME_PAR_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_QME_PAR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_QME_PAR_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_QME_PAR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_QME_PAR_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_QME_PAR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_QME_PAR_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_QME_PAR_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_QME_PAR_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_QME_PAR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_FORCE_0_QME(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_FORCE_0_QME,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_FORCE_0_QME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_FORCE_0_QME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_FORCE_0_QME,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_FORCE_0_QME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_FORCE_0_QME(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_FORCE_0_QME>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_FORCE_0_QME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_FORCE_0_QME(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_FORCE_0_QME>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_FORCE_0_QME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_FORCE_0_QME(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_FORCE_0_QME,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_FORCE_0_QME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_FORCE_0_QME(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_FORCE_0_QME>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_SLAVE_CONFIG_REG_FORCE_0_QME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_READ_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_READ_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_READ_PROTECT_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_READ_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_READ_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_READ_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_READ_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_READ_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_READ_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_READ_PROTECT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_READ_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_READ_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_READ_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN1_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_PRIMARY_ADDRESS_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_PRIMARY_ADDRESS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_PRIMARY_ADDRESS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_PRIMARY_ADDRESS_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_PRIMARY_ADDRESS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_PRIMARY_ADDRESS_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_PRIMARY_ADDRESS_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_PRIMARY_ADDRESS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR,
           TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR,
           TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR,
           TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR_OCB_PIB_OEAR_OCI_TIMEOUT_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_DBG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_DBG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_DBG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_DBG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_DBG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_DBG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_DBG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_DBG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_DBG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_DBG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_DBG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_DBG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_DBG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_DBG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_DBG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_DBG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_DBG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_DBG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_TRIG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_TRIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_TRIG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_TRIG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_TRIG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_TRIG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_TRIG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_HALT_ON_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_COVERAGE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_COVERAGE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_COVERAGE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_COVERAGE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_COVERAGE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_COVERAGE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_COVERAGE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_COVERAGE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_COVERAGE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_COVERAGE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_COVERAGE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_COVERAGE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_COVERAGE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_COVERAGE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_COVERAGE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_COVERAGE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_COVERAGE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_COVERAGE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_INTR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_INTR_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_INTR_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_INTR_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_INTR_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_INTR_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_INTR_ADDR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_INTR_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_INTR_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_INTR_ADDR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_INTR_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_INTR_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_INTR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_INTR_ADDR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_INTR_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_INTR_ADDR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_INTR_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_INTR_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_EXTRA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_EXTRA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_EXTRA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_EXTRA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_EXTRA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_EXTRA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_EXTRA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_EXTRA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_EXTRA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_EXTRA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_EXTRA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_EXTRA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_EXTRA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_EXTRA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_EXTRA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_EXTRA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_EXTRA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_EXTRA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_STALL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_STALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_STALL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_STALL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_STALL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_STALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_STALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_TRACE_STALL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_WAIT_CYCLES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_WAIT_CYCLES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_WAIT_CYCLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_WAIT_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_WAIT_CYCLES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_WAIT_CYCLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_WAIT_CYCLES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_WAIT_CYCLES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_WAIT_CYCLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_WAIT_CYCLES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_WAIT_CYCLES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_WAIT_CYCLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_WAIT_CYCLES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_WAIT_CYCLES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_WAIT_CYCLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_WAIT_CYCLES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_WAIT_CYCLES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_FULL_SPEED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_FULL_SPEED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_FULL_SPEED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_FULL_SPEED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_FULL_SPEED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_FULL_SPEED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_FULL_SPEED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_FULL_SPEED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_FULL_SPEED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_FULL_SPEED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_FULL_SPEED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_FULL_SPEED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_FULL_SPEED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_FULL_SPEED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_FULL_SPEED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_FULL_SPEED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_FULL_SPEED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_EN_FULL_SPEED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_DIS_FLOW_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_DIS_FLOW_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_DIS_FLOW_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_DIS_FLOW_CHANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_DIS_FLOW_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_DIS_FLOW_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_DIS_FLOW_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_DIS_FLOW_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_DIS_FLOW_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_DIS_FLOW_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_DIS_FLOW_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_DIS_FLOW_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_DIS_FLOW_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_DIS_FLOW_CHANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_DIS_FLOW_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_DIS_FLOW_CHANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_DIS_FLOW_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_DIS_FLOW_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_MODE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_MODE_SEL,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_MODE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_MODE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_MODE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_MODE_SEL,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_MODE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_MODE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_MODE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_MODE_SEL,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_MODE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_MODE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_RESERVED12_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_RESERVED12_15,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_RESERVED12_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_RESERVED12_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_RESERVED12_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_RESERVED12_15,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_RESERVED12_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_RESERVED12_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_RESERVED12_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_RESERVED12_15,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_RESERVED12_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_RESERVED12_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_FIR_TRIGGER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_FIR_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_FIR_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_FIR_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_FIR_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_FIR_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_FIR_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_FIR_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_FIR_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_FIR_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_FIR_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_FIR_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_FIR_TRIGGER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_FIR_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_FIR_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_FIR_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_FIR_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_FIR_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_SPARE,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_SPARE,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_SPARE,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_DATA_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_DATA_SEL,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_DATA_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_DATA_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_DATA_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_DATA_SEL,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_DATA_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_DATA_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_DATA_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_DATA_SEL,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_DATA_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEDBG_TRACE_DATA_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_LOW_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_MEM_HIGH_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_LOW_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_LOCAL_HIGH_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_LOW_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_SRAM_HIGH_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_SIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_SIB_PIB_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_SIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_SIB_PIB_IFETCH_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_SIB_PIB_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_SIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_SIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_SIB_PIB_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_SIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_SIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_SIB_PIB_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_SIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_SIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_SIB_PIB_IFETCH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_SIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_SIB_PIB_IFETCH_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_SIB_PIB_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_SIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_MEM_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_MEM_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_MEM_IFETCH_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_MEM_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_MEM_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_MEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_MEM_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_MEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_MEM_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_MEM_IFETCH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_MEM_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_MEM_IFETCH_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_MEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICAC_MEM_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_POPULATE_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BUSY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BUSY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IMPRECISE_ERROR_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IMPRECISE_ERROR_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BYTE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BYTE_ENABLE,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BYTE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BYTE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BYTE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BYTE_ENABLE,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BYTE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BYTE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BYTE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BYTE_ENABLE,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BYTE_ENABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_BYTE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_LINE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_LINE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_LINE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_LINE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_LINE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_LINE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_LINE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_LINE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_LINE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_LINE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_LINE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_LINE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_LINE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_LINE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_LINE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_LINE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_LINE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_LINE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_ERROR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_ERROR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_ERROR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IFETCH_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IFETCH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IFETCH_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_DATAOP_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_DATAOP_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_DATAOP_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_DATAOP_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_DATAOP_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_DATAOP_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_DATAOP_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_DATAOP_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_DATAOP_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_DATAOP_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEML_DATAOP_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA_OCB_OCI_GPEOXIXCR_XCR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA_OCB_OCI_GPEOXIXCR_XCR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA_OCB_OCI_GPEOXIXCR_XCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA_OCB_OCI_GPEOXIXCR_XCR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA_OCB_OCI_GPEOXIXCR_XCR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA_OCB_OCI_GPEOXIXCR_XCR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA_OCB_OCI_GPEOXIXCR_XCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA_OCB_OCI_GPEOXIXCR_XCR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA_OCB_OCI_GPEOXIXCR_XCR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA_OCB_OCI_GPEOXIXCR_XCR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA_OCB_OCI_GPEOXIXCR_XCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIRAMRA_OCB_OCI_GPEOXIXCR_XCR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_0,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_0,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_0,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_1,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_1,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_1,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_8,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_8,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_8,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_8_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_9,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_9,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_9,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_9_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR28_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_BAR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_BAR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_BAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_BAR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_BAR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_BAR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_SIZE,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_SIZE,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_SIZE,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPESWPR0_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28_OCB_OCI_GPEXIVDR28_GPR28(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28_OCB_OCI_GPEXIVDR28_GPR28,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28_OCB_OCI_GPEXIVDR28_GPR28_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28_OCB_OCI_GPEXIVDR28_GPR28 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28_OCB_OCI_GPEXIVDR28_GPR28(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28_OCB_OCI_GPEXIVDR28_GPR28,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28_OCB_OCI_GPEXIVDR28_GPR28_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28_OCB_OCI_GPEXIVDR28_GPR28 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28_OCB_OCI_GPEXIVDR28_GPR28(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28_OCB_OCI_GPEXIVDR28_GPR28,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28_OCB_OCI_GPEXIVDR28_GPR28_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR28_OCB_OCI_GPEXIVDR28_GPR28 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGB_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_4,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_4,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_4,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_5,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_5,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_5,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR4_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29_OCB_OCI_GPEXIVDR28_GPR29(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29_OCB_OCI_GPEXIVDR28_GPR29,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29_OCB_OCI_GPEXIVDR28_GPR29_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29_OCB_OCI_GPEXIVDR28_GPR29 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29_OCB_OCI_GPEXIVDR28_GPR29(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29_OCB_OCI_GPEXIVDR28_GPR29,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29_OCB_OCI_GPEXIVDR28_GPR29_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29_OCB_OCI_GPEXIVDR28_GPR29 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29_OCB_OCI_GPEXIVDR28_GPR29(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29_OCB_OCI_GPEXIVDR28_GPR29,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29_OCB_OCI_GPEXIVDR28_GPR29_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR29_OCB_OCI_GPEXIVDR28_GPR29 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_OXIXCR_XCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR_XICTR_CTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_DERP3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_DERP3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_DERP3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_DERP3;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_DERP3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_DERP3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_DERP3));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_DERP3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_DERP3_DEND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_DERP3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_DERP3_DEND,
           TP_TPCHIP_OCC_OCI_OCB_DERP3_DEND_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_DERP3_DEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_DERP3_DEND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_DERP3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_DERP3_DEND,
           TP_TPCHIP_OCC_OCI_OCB_DERP3_DEND_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_DERP3_DEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_DERP3_DEND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_DERP3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_DERP3_DEND,
           TP_TPCHIP_OCC_OCI_OCB_DERP3_DEND_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_DERP3_DEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_DERP3_SOR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_DERP3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_DERP3_SOR,
           TP_TPCHIP_OCC_OCI_OCB_DERP3_SOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_DERP3_SOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_DERP3_SOR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_DERP3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_DERP3_SOR,
           TP_TPCHIP_OCC_OCI_OCB_DERP3_SOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_DERP3_SOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_DERP3_SOR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_DERP3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_DERP3_SOR,
           TP_TPCHIP_OCC_OCI_OCB_DERP3_SOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_DERP3_SOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_FRAME_SIZE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_OUT_COUNT1_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_DELAY1_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF2_IN_COUNT1_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBSES1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSES1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBSES1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSES1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSES1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBSES1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSES1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES1_SH_READ_UNDERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES1));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES1_LL_WRITE_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B,
           TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B,
           TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIRR1B_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B,
           TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OIRR1B_OCB_OCI_OIRR1B_INTERRUPT_ROUTE_1_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OISR1_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OISR1_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OISR1_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OISR1_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_DEBUGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_TRACE_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE0_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_GPE1_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_CHECK_STOP_PPC405 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_EXTERNAL_TRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_TIMER1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_HI_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_HI_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_HI_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_I2CM_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_SPARE_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_DCM_INTF_ONGOING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_SEND_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBAX_OCC_PUSH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCDE_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_PBA_BCUE_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM0_PUSH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM1_PUSH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM2_PUSH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_OCC_STRM3_PUSH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI0_LO_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI1_LO_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OISR1_RO, TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OISR1_IPI4_LO_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1PRA_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6_OCB_OCI_OPIT1Q6RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6_OCB_OCI_OPIT1Q6RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6_OCB_OCI_OPIT1Q6RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6_OCB_OCI_OPIT1Q6RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6_OCB_OCI_OPIT1Q6RR_PCB_INTR_PAYLOAD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6_OCB_OCI_OPIT1Q6RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6_OCB_OCI_OPIT1Q6RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6_OCB_OCI_OPIT1Q6RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6_OCB_OCI_OPIT1Q6RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6_OCB_OCI_OPIT1Q6RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6_OCB_OCI_OPIT1Q6RR_PCB_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1Q6_OCB_OCI_OPIT1Q6RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2_OCB_OCI_OPIT2Q2RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2_OCB_OCI_OPIT2Q2RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2_OCB_OCI_OPIT2Q2RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2_OCB_OCI_OPIT2Q2RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2_OCB_OCI_OPIT2Q2RR_PCB_INTR_PAYLOAD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2_OCB_OCI_OPIT2Q2RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2_OCB_OCI_OPIT2Q2RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2_OCB_OCI_OPIT2Q2RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2_OCB_OCI_OPIT2Q2RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2_OCB_OCI_OPIT2Q2RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2_OCB_OCI_OPIT2Q2RR_PCB_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT2Q2_OCB_OCI_OPIT2Q2RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4_OCB_OCI_OPIT5Q4RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4_OCB_OCI_OPIT5Q4RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4_OCB_OCI_OPIT5Q4RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4_OCB_OCI_OPIT5Q4RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4_OCB_OCI_OPIT5Q4RR_PCB_INTR_PAYLOAD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4_OCB_OCI_OPIT5Q4RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4_OCB_OCI_OPIT5Q4RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4_OCB_OCI_OPIT5Q4RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4_OCB_OCI_OPIT5Q4RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4_OCB_OCI_OPIT5Q4RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4_OCB_OCI_OPIT5Q4RR_PCB_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT5Q4_OCB_OCI_OPIT5Q4RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0_OCB_OCI_OPIT6Q0RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0_OCB_OCI_OPIT6Q0RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0_OCB_OCI_OPIT6Q0RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0_OCB_OCI_OPIT6Q0RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0_OCB_OCI_OPIT6Q0RR_PCB_INTR_PAYLOAD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0_OCB_OCI_OPIT6Q0RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0_OCB_OCI_OPIT6Q0RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0_OCB_OCI_OPIT6Q0RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0_OCB_OCI_OPIT6Q0RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0_OCB_OCI_OPIT6Q0RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0_OCB_OCI_OPIT6Q0RR_PCB_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT6Q0_OCB_OCI_OPIT6Q0RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C11RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C23RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT8C4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8C4;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT8C4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C4));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8C4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C4));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8C4));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8C4_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_RO, TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT8PRB_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C16RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_SOURCE_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_SOURCE_CORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_SOURCE_CORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_SOURCE_CORE,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_SOURCE_CORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_SOURCE_CORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_PAYLOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_PAYLOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT9C24RR_PAYLOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO, TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_RO_CLRPART));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPITAPRC_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_P2S_CR2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_P2S_CR2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_P2S_CR2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_CR2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_P2S_CR2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_CR2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_CR2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY,
           TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_CR2_OCB_OCI_P2S_CR2_INTER_FRAME_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2_OCB_OCI_WOFICDCM2_DCM_MESSAGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2_OCB_OCI_WOFICDCM2_DCM_MESSAGE,
           TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2_OCB_OCI_WOFICDCM2_DCM_MESSAGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2_OCB_OCI_WOFICDCM2_DCM_MESSAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2_OCB_OCI_WOFICDCM2_DCM_MESSAGE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2_OCB_OCI_WOFICDCM2_DCM_MESSAGE,
           TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2_OCB_OCI_WOFICDCM2_DCM_MESSAGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2_OCB_OCI_WOFICDCM2_DCM_MESSAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2_OCB_OCI_WOFICDCM2_DCM_MESSAGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2_OCB_OCI_WOFICDCM2_DCM_MESSAGE,
           TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2_OCB_OCI_WOFICDCM2_DCM_MESSAGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_WOFICDCM2_OCB_OCI_WOFICDCM2_DCM_MESSAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_SRC_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RUN_TCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_TCK_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_JTAG_TRST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_RW, TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDI_OCB_PIB_OJTDI_JTAG_TDI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113_REGISTER113(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113_REGISTER113,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113_REGISTER113_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113_REGISTER113 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113_REGISTER113(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113_REGISTER113,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113_REGISTER113_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113_REGISTER113 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113_REGISTER113(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113));
#endif
    return i_data.extractToRight<TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113_REGISTER113,
           TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113_REGISTER113_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG113_REGISTER113 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}


}
}

#endif
