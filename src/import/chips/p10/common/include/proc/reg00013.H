/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00013.H $         */
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

#ifndef __PROC_REG00013_H_
#define __PROC_REG00013_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_LLSTAT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_LLSTAT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_LLSTAT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_LLSTAT;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_LLSTAT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_LLSTAT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_LLSTAT));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_LLSTAT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_IPOLL_AND_DMA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_IPOLL_AND_DMA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_IPOLL_AND_DMA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_IPOLL_AND_DMA(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_IPOLL_AND_DMA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_IPOLL_AND_DMA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_IPOLL_AND_DMA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_IPOLL_AND_DMA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_IPOLL_AND_DMA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_IPOLL_AND_DMA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_IPOLL_AND_DMA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_IPOLL_AND_DMA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_IPOLL_AND_DMA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_IPOLL_AND_DMA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_IPOLL_AND_DMA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_IPOLL_AND_DMA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_IPOLL_AND_DMA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_IPOLL_AND_DMA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_HW_ERROR_RECOVERY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_PARITY_CHECK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_PARITY_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_PARITY_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_PARITY_CHECK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_PARITY_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_PARITY_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_PARITY_CHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_PARITY_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_PARITY_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_PARITY_CHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_PARITY_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_PARITY_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_PARITY_CHECK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_PARITY_CHECK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_PARITY_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_PARITY_CHECK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_PARITY_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_ENABLE_PARITY_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_0,
           TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_0,
           TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_0,
           TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_1,
           TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_1,
           TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_1,
           TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_RATE_SELECTION_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_DIV_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_DIV_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_DIV_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_DIV_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_DIV_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_DIV_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_DIV_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_DIV_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_DIV_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_DIV_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_DIV_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_DIV_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_DIV_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_DIV_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_DIV_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_DIV_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_DIV_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_CLOCK_DIV_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_TIMEOUT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_TIMEOUT_SEL,
           TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_TIMEOUT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_TIMEOUT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_TIMEOUT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_TIMEOUT_SEL,
           TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_TIMEOUT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_TIMEOUT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_TIMEOUT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_TIMEOUT_SEL,
           TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_TIMEOUT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_TIMEOUT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RECEIVER_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RECEIVER_MODE,
           TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RECEIVER_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RECEIVER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RECEIVER_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RECEIVER_MODE,
           TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RECEIVER_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RECEIVER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RECEIVER_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RECEIVER_MODE,
           TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RECEIVER_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MMODE_RECEIVER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_WO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_WO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_WO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_WO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_WO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_WO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_WO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_WO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_WO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_GENERAL_RESET_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_WO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_GENERAL_RESET_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_GENERAL_RESET_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_GENERAL_RESET_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_WO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_GENERAL_RESET_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_GENERAL_RESET_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_GENERAL_RESET_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_WO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_GENERAL_RESET_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_GENERAL_RESET_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_GENERAL_RESET_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_WO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_GENERAL_RESET_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_GENERAL_RESET_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_GENERAL_RESET_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_WO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_GENERAL_RESET_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_GENERAL_RESET_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_GENERAL_RESET_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_WO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_GENERAL_RESET_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_GENERAL_RESET_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_ERROR_RESET_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_WO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_ERROR_RESET_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_ERROR_RESET_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_ERROR_RESET_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_WO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_ERROR_RESET_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_ERROR_RESET_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_ERROR_RESET_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_WO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_ERROR_RESET_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_ERROR_RESET_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_ERROR_RESET_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_WO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_ERROR_RESET_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_ERROR_RESET_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_ERROR_RESET_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_WO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_ERROR_RESET_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_ERROR_RESET_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_ERROR_RESET_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_WO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_ERROR_RESET_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP3_ERROR_RESET_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP0_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP0_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP0_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP0_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP0_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP0_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP0_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP0_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP0_SCOMFSI0(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP0_SCOMFSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP0_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP0_SCOMFSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP0_SCOMFSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP0_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP0_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP0_SCOMFSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MVER_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MVER_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MVER_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MVER_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MVER_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MVER_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MVER_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MVER_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MVER_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MVER_SCOMFSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MVER_SCOMFSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MVER_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MVER_SCOMFSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MVER_SCOMFSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MVER_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MVER_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MVER_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MVER_SCOMFSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP1_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP1_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP1_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP1_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP1_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP1_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP1_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP1_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP1_SCOMFSI0(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP1_SCOMFSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP1_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP1_SCOMFSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP1_SCOMFSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP1_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP1_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP1_SCOMFSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP0_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP0_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP0_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP0_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP0_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP0_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP0_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP0_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP0_SCOMFSI0(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP0_SCOMFSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP0_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP0_SCOMFSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP0_SCOMFSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP0_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP0_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP0_SCOMFSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_0,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_0,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_0,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_1,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_1,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_1,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_2,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_2,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_2,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SNMR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SNMR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SNMR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SNMR;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SNMR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SNMR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SNMR));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SNMR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SSISM(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SSISM;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SSISM(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SSISM;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SSISM, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SSISM(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SSISM));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SSISM, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SSTAT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SSTAT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SSTAT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SSTAT;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SSTAT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SSTAT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SSTAT));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SSTAT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP7_FSI1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP7_FSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP7_FSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP7_FSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP7_FSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP7_FSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP7_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP7_SCOMFSI1));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP7_FSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP7_SCOMFSI1(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP7_SCOMFSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP7_SCOMFSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP7_SCOMFSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP7_SCOMFSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP7_SCOMFSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP7_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP7_SCOMFSI1));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP7_SCOMFSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_0_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_0_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_0_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_0_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_1_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_1_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_1_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_1_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_2_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_2_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_2_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_2_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_2_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_2_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_2_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_2_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_2_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_3_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_3_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_3_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_3_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_3_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_3_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_3_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_3_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_3_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_4_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_4_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_4_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_4_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_4_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_4_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_4_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_4_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_4_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_4_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_4_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_4_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_5_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_5_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_5_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_5_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_5_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_5_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_5_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_5_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_5_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_5_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_5_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_5_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_6_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_6_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_6_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_6_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_6_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_6_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_6_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_6_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_6_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_6_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_6_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_6_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_6_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_6_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_6_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_6_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_6_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_6_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_7_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_7_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_7_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_7_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_7_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_7_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_7_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_7_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_7_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_7_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_7_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_7_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MCENP0_7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_0_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_0_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_0_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_0_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_1_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_1_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_1_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_1_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_2_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_2_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_2_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_2_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_2_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_2_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_2_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_2_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_2_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_3_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_3_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_3_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_3_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_3_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_3_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_3_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_3_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_3_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_4_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_4_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_4_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_4_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_4_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_4_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_4_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_4_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_4_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_4_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_4_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_4_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_5_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_5_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_5_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_5_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_5_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_5_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_5_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_5_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_5_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_5_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_5_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_5_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_5_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_6_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_6_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_6_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_6_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_6_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_6_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_6_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_6_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_6_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_6_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_6_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_6_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_6_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_6_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_6_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_6_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_6_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_6_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_7_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_7_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_7_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_7_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_7_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_7_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_7_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_7_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_7_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_7_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_7_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_7_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP0_7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_FSI1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_FSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_FSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_FSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_FSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_FSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_FSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_0,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_0,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_0,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_1,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_1,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_1,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_2,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_2,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_2,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP6_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MVER_FSI1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MVER_FSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MVER_FSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MVER_FSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MVER_FSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MVER_FSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MVER_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MVER_SCOMFSI1));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MVER_FSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MVER_SCOMFSI1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MVER_SCOMFSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MVER_SCOMFSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MVER_SCOMFSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MVER_SCOMFSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MVER_SCOMFSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MVER_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MVER_SCOMFSI1));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MVER_SCOMFSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_SLBUS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SLBUS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_SLBUS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SLBUS;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SLBUS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_SLBUS(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SLBUS));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SLBUS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_SRSIM0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SRSIM0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_SRSIM0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SRSIM0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SRSIM0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_SRSIM0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SRSIM0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SRSIM0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_PEEK4A4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_PEEK4A4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_PEEK4A4;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_PEEK4A4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_PEEK4A4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_PEEK4A4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_6_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_6_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_6_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_6_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_6_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_6_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_6_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_6_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_6_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_6_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_6_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_6_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_6_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_6_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_6_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_6_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_6_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_6_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_7_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_7_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_7_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_7_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_7_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_7_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_7_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_7_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_7_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_7_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_7_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_7_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_0_PORT_7_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_ACTUAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_ACTUAL_ERROR,
           TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_ACTUAL_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_ACTUAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_ACTUAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_ACTUAL_ERROR,
           TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_ACTUAL_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_ACTUAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_ACTUAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_ACTUAL_ERROR,
           TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_ACTUAL_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_ACTUAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_0_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_0_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_0_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_0_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_2_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_2_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_2_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_2_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_2_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_2_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_2_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_2_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_2_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_3_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_3_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_3_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_3_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_3_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_3_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_3_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_3_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_3_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_4_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_4_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_4_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_4_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_4_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_4_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_4_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_4_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_4_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_4_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_4_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_PEEK4A4));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_4_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_PEEK4A4_1_PORT_4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_RECEIVE_DATA_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_RECEIVE_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_RECEIVE_DATA_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_RECEIVE_DATA_REG;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_RECEIVE_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_RECEIVE_DATA_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_RECEIVE_DATA_REG));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_RECEIVE_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_RECEIVE_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_RECEIVE_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_RECEIVE_DATA_REG));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_MISO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_MISO,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_MISO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_MISO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_MISO(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_MISO,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_MISO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_MISO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_MISO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_MISO,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_MISO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_MISO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_MOSI(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_MOSI,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_MOSI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_MOSI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_MOSI(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_MOSI,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_MOSI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_MOSI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_MOSI(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_MOSI,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_MOSI_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_MOSI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_DIRECTMODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_DIRECTMODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_DIRECTMODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_DIRECTMODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_DIRECTMODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_DIRECTMODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_DIRECTMODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_DIRECTMODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_DIRECTMODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_DIRECTMODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_DIRECTMODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_DIRECTMODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_DIRECTMODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_DIRECTMODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_DIRECTMODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_DIRECTMODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_DIRECTMODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_DIRECTMODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_EN_C4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_EN_C4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_EN_C4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_EN_C4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_EN_C4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_EN_C4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_EN_C4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_EN_C4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_EN_C4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_EN_C4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_EN_C4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_EN_C4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_EN_C4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_EN_C4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_EN_C4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_EN_C4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_EN_C4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_EN_C4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCS_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCS_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCS_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCS_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCS_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCS_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCS_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCS_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCS_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCS_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCS_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCS_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCS_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCS_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCS_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCS_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCS_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCS_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_IO_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_IO_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_IO_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_IO_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_IO_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_IO_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_IO_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_IO_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_IO_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_IO_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_IO_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_IO_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_INVERT_PORTS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_INVERT_PORTS,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_INVERT_PORTS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_INVERT_PORTS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_INVERT_PORTS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_INVERT_PORTS,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_INVERT_PORTS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_INVERT_PORTS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_INVERT_PORTS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_INVERT_PORTS,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_INVERT_PORTS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_INVERT_PORTS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SLAVE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SLAVE_RESET,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SLAVE_RESET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SLAVE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SLAVE_RESET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SLAVE_RESET,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SLAVE_RESET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SLAVE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SLAVE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SLAVE_RESET,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SLAVE_RESET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_SPI_SLAVE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_LOOPBACK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_LOOPBACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_LOOPBACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_LOOPBACK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_LOOPBACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_LOOPBACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_LOOPBACK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_LOOPBACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_LOOPBACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_LOOPBACK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_LOOPBACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_LOOPBACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_LOOPBACK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_LOOPBACK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_LOOPBACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_LOOPBACK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_RW_WOR));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_LOOPBACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_PORT_CONTROL_LOOPBACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_EG_SCF_ERRINJSO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_EG_SCF_ERRINJSO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_EG_SCF_ERRINJSO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_EG_SCF_ERRINJSO;
#endif
    return fapi2::getScom(i_target, VAS_VA_EG_SCF_ERRINJSO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_EG_SCF_ERRINJSO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return fapi2::putScom(i_target, VAS_VA_EG_SCF_ERRINJSO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_ERRINJSO_WC_ENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_ERRINJSO_WC_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_WC_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_ERRINJSO_WC_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_ERRINJSO_WC_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_WC_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_ERRINJSO_WC_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_ERRINJSO_WC_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_WC_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_ERRINJSO_WC_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_ERRINJSO_WC_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_WC_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_ERRINJSO_WC_ENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_ERRINJSO_WC_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_WC_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_ERRINJSO_WC_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_ERRINJSO_WC_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_WC_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_ERRINJSO_WC_TYP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_ERRINJSO_WC_TYP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_WC_TYP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_ERRINJSO_WC_TYP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_ERRINJSO_WC_TYP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_WC_TYP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_ERRINJSO_WC_TYP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_ERRINJSO_WC_TYP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_WC_TYP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_ERRINJSO_WC_TYP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_ERRINJSO_WC_TYP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_WC_TYP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_ERRINJSO_WC_TYP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_ERRINJSO_WC_TYP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_WC_TYP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_ERRINJSO_WC_TYP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_ERRINJSO_WC_TYP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_WC_TYP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_ERRINJSO_WC_FRQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_ERRINJSO_WC_FRQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_WC_FRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_ERRINJSO_WC_FRQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_ERRINJSO_WC_FRQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_WC_FRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_ERRINJSO_WC_FRQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_ERRINJSO_WC_FRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_WC_FRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_ERRINJSO_WC_FRQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_ERRINJSO_WC_FRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_WC_FRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_ERRINJSO_WC_FRQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_ERRINJSO_WC_FRQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_WC_FRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_ERRINJSO_WC_FRQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_ERRINJSO_WC_FRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_WC_FRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_ERRINJSO_WC_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_ERRINJSO_WC_SEL,
           VAS_VA_EG_SCF_ERRINJSO_WC_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_WC_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_ERRINJSO_WC_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_ERRINJSO_WC_SEL,
           VAS_VA_EG_SCF_ERRINJSO_WC_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_WC_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_ERRINJSO_WC_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_ERRINJSO_WC_SEL,
           VAS_VA_EG_SCF_ERRINJSO_WC_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_WC_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_ERRINJSO_EG_ENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_ERRINJSO_EG_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_EG_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_ERRINJSO_EG_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_ERRINJSO_EG_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_EG_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_ERRINJSO_EG_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_ERRINJSO_EG_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_EG_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_ERRINJSO_EG_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_ERRINJSO_EG_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_EG_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_ERRINJSO_EG_ENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_ERRINJSO_EG_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_EG_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_ERRINJSO_EG_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_ERRINJSO_EG_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_EG_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_ERRINJSO_EG_TYP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_ERRINJSO_EG_TYP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_EG_TYP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_ERRINJSO_EG_TYP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_ERRINJSO_EG_TYP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_EG_TYP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_ERRINJSO_EG_TYP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_ERRINJSO_EG_TYP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_EG_TYP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_ERRINJSO_EG_TYP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_ERRINJSO_EG_TYP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_EG_TYP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_ERRINJSO_EG_TYP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_ERRINJSO_EG_TYP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_EG_TYP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_ERRINJSO_EG_TYP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_ERRINJSO_EG_TYP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_EG_TYP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_ERRINJSO_EG_FRQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_ERRINJSO_EG_FRQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_EG_FRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_ERRINJSO_EG_FRQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_ERRINJSO_EG_FRQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_EG_FRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_ERRINJSO_EG_FRQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_ERRINJSO_EG_FRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_EG_FRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_ERRINJSO_EG_FRQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_ERRINJSO_EG_FRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_EG_FRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_ERRINJSO_EG_FRQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_ERRINJSO_EG_FRQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_EG_FRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_ERRINJSO_EG_FRQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_ERRINJSO_EG_FRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_EG_FRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_ERRINJSO_EG_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_ERRINJSO_EG_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_EG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_ERRINJSO_EG_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_ERRINJSO_EG_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_EG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_ERRINJSO_EG_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_ERRINJSO_EG_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_EG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_ERRINJSO_EG_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_ERRINJSO_EG_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_EG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_ERRINJSO_EG_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_ERRINJSO_EG_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_EG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_ERRINJSO_EG_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_ERRINJSO));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_ERRINJSO_EG_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_ERRINJSO_EG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_EG_SCF_PGMIG1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_EG_SCF_PGMIG1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_EG_SCF_PGMIG1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_EG_SCF_PGMIG1;
#endif
    return fapi2::getScom(i_target, VAS_VA_EG_SCF_PGMIG1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_EG_SCF_PGMIG1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PGMIG1));
#endif
    return fapi2::putScom(i_target, VAS_VA_EG_SCF_PGMIG1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_RGERRRPT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_RGERRRPT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_RGERRRPT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_RGERRRPT;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_RGERRRPT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_RGERRRPT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_RGERRRPT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_RGERRRPT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_RGERRRPT_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_RGERRRPT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_RGERRRPT_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_RGERRRPT_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_RGERRRPT_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_RGERRRPT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_RGERRRPT_BIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_RGERRRPT_BIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_RGERRRPT_BIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_RGERRRPT_BIT4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_RGERRRPT_BIT4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_RGERRRPT_BIT4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_RGERRRPT_BIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_RGERRRPT_BIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_RGERRRPT_BIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_RGERRRPT_BIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_RGERRRPT_BIT5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_RGERRRPT_BIT5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_RGERRRPT_BIT5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_RGERRRPT_BIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_RGERRRPT_BIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_RGERRRPT_BIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_RGERRRPT_BIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_RGERRRPT_BIT6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_RGERRRPT_BIT6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_RGERRRPT_BIT6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_RGERRRPT_BIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_RGERRRPT_BIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_RGERRRPT_BIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_RGERRRPT_BIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_RGERRRPT_BIT7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_RGERRRPT_BIT7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_RGERRRPT_BIT7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_RGERRRPT_BIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_RGERRRPT_BIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_RGERRRPT_BIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_RGERRRPT_BIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_RGERRRPT_BIT8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_RGERRRPT_BIT8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_RGERRRPT_BIT8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_RGERRRPT_BIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_RGERRRPT_BIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_RGERRRPT_BIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_RGERRRPT_BIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_RGERRRPT_BIT9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_RGERRRPT_BIT9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_RGERRRPT_BIT9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_RGERRRPT_BIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_RGERRRPT_BIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_RGERRRPT_BIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_RGERRRPT_BIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_RGERRRPT_BIT10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_RGERRRPT_BIT10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_RGERRRPT_BIT10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_RGERRRPT_BIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_RGERRRPT_BIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_RGERRRPT_BIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_RGERRRPT_BIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_RGERRRPT_BIT11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_RGERRRPT_BIT11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_RGERRRPT_BIT11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_RGERRRPT_BIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_RGERRRPT_BIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_RGERRRPT_BIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_RGERRRPT_BIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_RGERRRPT_BIT12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_RGERRRPT_BIT12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_RGERRRPT_BIT12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_RGERRRPT_BIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RGERRRPT_BIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RGERRRPT_BIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_RGERRRPT_BIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_RGERRRPT_BIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_RGERRRPT_BIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_RGERRRPT_BIT13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_RGERRRPT_BIT13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_RGERRRPT_BIT13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RGERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_RGERRRPT_BIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RGERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_RMABAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_RMABAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_RMABAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_RMABAR;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_RMABAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_RMABAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RMABAR));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_RMABAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RMABAR_RMA_BAR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RMABAR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RMABAR_RMA_BAR,
           VAS_VA_RG_SCF_RMABAR_RMA_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RMABAR_RMA_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_RMABAR_RMA_BAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RMABAR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_RMABAR_RMA_BAR,
           VAS_VA_RG_SCF_RMABAR_RMA_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RMABAR_RMA_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_RMABAR_RMA_BAR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RMABAR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_RMABAR_RMA_BAR,
           VAS_VA_RG_SCF_RMABAR_RMA_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_RMABAR_RMA_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_WRMON2BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON2BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_WRMON2BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON2BAR;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_WRMON2BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_WRMON2BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WRMON2BAR));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_WRMON2BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_WRMON6CMP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON6CMP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_WRMON6CMP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON6CMP;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_WRMON6CMP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_WRMON6CMP(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WRMON6CMP));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_WRMON6CMP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_WRMON7WID(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON7WID;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_WRMON7WID(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON7WID;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_WRMON7WID, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_WRMON7WID(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WRMON7WID));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_WRMON7WID, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}



#ifndef __PPE_HCODE__
}
}

#endif
#endif
