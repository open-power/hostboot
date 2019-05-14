/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00030.H $         */
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

#ifndef __PROC_REG00030_H_
#define __PROC_REG00030_H_

namespace scomt
{
namespace proc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_XSTOP_MASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_XSTOP_MASK_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_XSTOP_MASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_XSTOP_MASK_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_XSTOP_MASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_XSTOP_MASK_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_XSTOP_MASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_XSTOP_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_XSTOP_MASK_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_XSTOP_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_XSTOP_MASK_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_XSTOP_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_XSTOP_MASK_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_XSTOP_MASK_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_XSTOP_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_XSTOP_MASK_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_XSTOP_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_XSTOP_MASK_53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_XSTOP_MASK_53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_TPC_XSTOP_MASK_53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_XSTOP_MASK_RW, TP_TPCHIP_TPC_XSTOP_MASK_WO_CLEAR, TP_TPCHIP_TPC_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_XSTOP_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_TPC_XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0,
           TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0,
           TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0,
           TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_RW(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_RW(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_RW;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_RW(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_RW(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_RW(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_RW;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_RW(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_RW(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_RW(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_RW;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_RW(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_RW(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_RW(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_RW;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_RW(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_RW(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_RW(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_RW;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_RW(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_RW(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_RW(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_RW;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_RW(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_M1HC2A_MAILBOX_1_HEADER_COMMAND_2_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_M1HC2A_MAILBOX_1_HEADER_COMMAND_2_A,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_M1HC2A_MAILBOX_1_HEADER_COMMAND_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_M1HC2A_MAILBOX_1_HEADER_COMMAND_2_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_M1HC2A_MAILBOX_1_HEADER_COMMAND_2_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_M1HC2A_MAILBOX_1_HEADER_COMMAND_2_A,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_M1HC2A_MAILBOX_1_HEADER_COMMAND_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_M1HC2A_MAILBOX_1_HEADER_COMMAND_2_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_M1HC2A_MAILBOX_1_HEADER_COMMAND_2_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_M1HC2A_MAILBOX_1_HEADER_COMMAND_2_A,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_M1HC2A_MAILBOX_1_HEADER_COMMAND_2_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_M1HC2A_MAILBOX_1_HEADER_COMMAND_2_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_RO(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_RO(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_RO(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_M2HC2B_MAILBOX_2_HEADER_COMMAND_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_M2HC2B_MAILBOX_2_HEADER_COMMAND_B,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_M2HC2B_MAILBOX_2_HEADER_COMMAND_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_M2HC2B_MAILBOX_2_HEADER_COMMAND_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_M2HC2B_MAILBOX_2_HEADER_COMMAND_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_M2HC2B_MAILBOX_2_HEADER_COMMAND_B,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_M2HC2B_MAILBOX_2_HEADER_COMMAND_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_M2HC2B_MAILBOX_2_HEADER_COMMAND_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_M2HC2B_MAILBOX_2_HEADER_COMMAND_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_FSI_BYTE,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_M2HC2B_MAILBOX_2_HEADER_COMMAND_B,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_M2HC2B_MAILBOX_2_HEADER_COMMAND_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_M2HC2B_MAILBOX_2_HEADER_COMMAND_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RO(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RO(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RO(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RCS_EVENTLOG_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RCS_EVENTLOG_3,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RCS_EVENTLOG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RCS_EVENTLOG_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RCS_EVENTLOG_3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RCS_EVENTLOG_3,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RCS_EVENTLOG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RCS_EVENTLOG_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RCS_EVENTLOG_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RCS_EVENTLOG_3,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RCS_EVENTLOG_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_RCS_EL3_RCS_EVENTLOG_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_DEBUG_BOLT_ON_CONTROL_BITS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_DEBUG_BOLT_ON_CONTROL_BITS,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_DEBUG_BOLT_ON_CONTROL_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_DEBUG_BOLT_ON_CONTROL_BITS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_DEBUG_BOLT_ON_CONTROL_BITS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_DEBUG_BOLT_ON_CONTROL_BITS,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_DEBUG_BOLT_ON_CONTROL_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_DEBUG_BOLT_ON_CONTROL_BITS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_DEBUG_BOLT_ON_CONTROL_BITS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_DEBUG_BOLT_ON_CONTROL_BITS,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_DEBUG_BOLT_ON_CONTROL_BITS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_DEBUG_BOLT_ON_CONTROL_BITS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_RW(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_RW;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_HDNFIFO_MCT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_HDNFIFO_MCT,
           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_HDNFIFO_MCT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_HDNFIFO_MCT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_HDNFIFO_MCT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_HDNFIFO_MCT,
           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_HDNFIFO_MCT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_HDNFIFO_MCT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_HDNFIFO_MCT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_HDNFIFO_MCT,
           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_HDNFIFO_MCT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HDOWNFIFO_MTC_HDNFIFO_MCT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_DATA_OUT(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_DATA_OUT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_DATA_OUT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_DATA_OUT;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_DATA_OUT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_DATA_OUT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_DATA_OUT));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_DATA_OUT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SBE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SBE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SBE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SBE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SBE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SBE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SBE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SBE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SBE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SBE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SBE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SBE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SBE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SBE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SBE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SBE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SBE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_REQ_RESET_FR_SBE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_DEQUEUED_EOT_FLAG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_DEQUEUED_EOT_FLAG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_DEQUEUED_EOT_FLAG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_DEQUEUED_EOT_FLAG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_DEQUEUED_EOT_FLAG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_DEQUEUED_EOT_FLAG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_DEQUEUED_EOT_FLAG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_DEQUEUED_EOT_FLAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_DEQUEUED_EOT_FLAG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_DEQUEUED_EOT_FLAG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_DEQUEUED_EOT_FLAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_DEQUEUED_EOT_FLAG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_DEQUEUED_EOT_FLAG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_DEQUEUED_EOT_FLAG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_DEQUEUED_EOT_FLAG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_DEQUEUED_EOT_FLAG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_DEQUEUED_EOT_FLAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_DEQUEUED_EOT_FLAG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_FULL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_FULL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_FULL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_FULL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EMPTY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EMPTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EMPTY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EMPTY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EMPTY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EMPTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_ENTRY_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_ENTRY_COUNT,
           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_ENTRY_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_ENTRY_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_ENTRY_COUNT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_ENTRY_COUNT,
           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_ENTRY_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_ENTRY_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_ENTRY_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_ENTRY_COUNT,
           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_ENTRY_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_ENTRY_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_VALID_FLAGS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_VALID_FLAGS,
           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_VALID_FLAGS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_VALID_FLAGS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_VALID_FLAGS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_VALID_FLAGS,
           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_VALID_FLAGS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_VALID_FLAGS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_VALID_FLAGS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_VALID_FLAGS,
           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_VALID_FLAGS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_VALID_FLAGS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EOT_FLAGS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EOT_FLAGS,
           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EOT_FLAGS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EOT_FLAGS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EOT_FLAGS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EOT_FLAGS,
           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EOT_FLAGS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EOT_FLAGS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EOT_FLAGS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EOT_FLAGS,
           TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EOT_FLAGS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_HUPFIFO_STATUS_FIFO_EOT_FLAGS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FIFO_SIZE_EQ_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FIFO_SIZE_EQ_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FIFO_SIZE_EQ_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FIFO_SIZE_EQ_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FIFO_SIZE_EQ_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FIFO_SIZE_EQ_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FIFO_SIZE_EQ_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FIFO_SIZE_EQ_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FIFO_SIZE_EQ_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FIFO_SIZE_EQ_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FIFO_SIZE_EQ_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FIFO_SIZE_EQ_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FIFO_SIZE_EQ_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FIFO_SIZE_EQ_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FIFO_SIZE_EQ_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FIFO_SIZE_EQ_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FIFO_SIZE_EQ_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FIFO_SIZE_EQ_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_FSI, TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_FSI, TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_READ_BUFFER_REG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_FSI, TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_READ_BUFFER_REG,
           TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_READ_BUFFER_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_READ_BUFFER_REG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_READ_BUFFER_REG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_FSI, TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_READ_BUFFER_REG,
           TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_READ_BUFFER_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_READ_BUFFER_REG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_READ_BUFFER_REG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_FSI, TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_READ_BUFFER_REG,
           TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_READ_BUFFER_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_READ_BUFFER_REG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_LSTAT(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_LSTAT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_LSTAT(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_LSTAT;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_LSTAT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_LSTAT(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_LSTAT));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_LSTAT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP2_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP2_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP2_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP2_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP2_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP2_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP2_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP2_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP2_SCOMFSI0(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP2_SCOMFSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP2_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP2_SCOMFSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP2_SCOMFSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP2_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP2_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP2_SCOMFSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MECTRL_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MECTRL_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MECTRL_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MECTRL_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MECTRL_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MECTRL_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MECTRL_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MECTRL_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MECTRL_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MECTRL_SCOMFSI0(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MECTRL_SCOMFSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MECTRL_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MECTRL_SCOMFSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MECTRL_SCOMFSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MECTRL_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MECTRL_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MECTRL_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MECTRL_SCOMFSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MLEVP1_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MLEVP1_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MLEVP1_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MLEVP1_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MLEVP1_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MLEVP1_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MLEVP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MLEVP1_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MLEVP1_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MLEVP1_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MLEVP1_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MLEVP1_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MLEVP1_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MLEVP1_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MLEVP1_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MLEVP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MLEVP1_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MLEVP1_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_0,
           TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_0,
           TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_0,
           TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_1,
           TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_1,
           TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_1,
           TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_2,
           TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_2,
           TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_2,
           TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAEB_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAEB_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAEB_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAEB_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAEB_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAEB_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAEB_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAEB_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAEB_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAEB_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAEB_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAEB_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAEB_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAEB_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAEB_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAEB_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAEB_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAEB_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_IPOLL_AND_DMA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_IPOLL_AND_DMA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_IPOLL_AND_DMA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_IPOLL_AND_DMA(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_IPOLL_AND_DMA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_IPOLL_AND_DMA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_IPOLL_AND_DMA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_IPOLL_AND_DMA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_IPOLL_AND_DMA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_IPOLL_AND_DMA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_IPOLL_AND_DMA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_IPOLL_AND_DMA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_IPOLL_AND_DMA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_IPOLL_AND_DMA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_IPOLL_AND_DMA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_IPOLL_AND_DMA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_IPOLL_AND_DMA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_IPOLL_AND_DMA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_HW_ERROR_RECOVERY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_HW_ERROR_RECOVERY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_HW_ERROR_RECOVERY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_HW_ERROR_RECOVERY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_HW_ERROR_RECOVERY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_HW_ERROR_RECOVERY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_HW_ERROR_RECOVERY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_HW_ERROR_RECOVERY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_HW_ERROR_RECOVERY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_HW_ERROR_RECOVERY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_HW_ERROR_RECOVERY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_HW_ERROR_RECOVERY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_HW_ERROR_RECOVERY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_HW_ERROR_RECOVERY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_HW_ERROR_RECOVERY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_HW_ERROR_RECOVERY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_HW_ERROR_RECOVERY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_HW_ERROR_RECOVERY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_PARITY_CHECK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_PARITY_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_PARITY_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_PARITY_CHECK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_PARITY_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_PARITY_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_PARITY_CHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_PARITY_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_PARITY_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_PARITY_CHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_PARITY_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_PARITY_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_PARITY_CHECK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_PARITY_CHECK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_PARITY_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_PARITY_CHECK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_PARITY_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_PARITY_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_0,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_0,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_0,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_1,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_1,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_1,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_DIV_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_DIV_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_DIV_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_DIV_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_DIV_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_DIV_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_DIV_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_DIV_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_DIV_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_DIV_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_DIV_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_DIV_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_DIV_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_DIV_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_DIV_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_DIV_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_DIV_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_DIV_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_TIMEOUT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_TIMEOUT_SEL,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_TIMEOUT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_TIMEOUT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_TIMEOUT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_TIMEOUT_SEL,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_TIMEOUT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_TIMEOUT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_TIMEOUT_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_TIMEOUT_SEL,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_TIMEOUT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_TIMEOUT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RECEIVER_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RECEIVER_MODE,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RECEIVER_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RECEIVER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RECEIVER_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RECEIVER_MODE,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RECEIVER_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RECEIVER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RECEIVER_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RECEIVER_MODE,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RECEIVER_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RECEIVER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP0_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP0_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP0_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP0_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP0_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP0_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP0_WO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP0_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP0_WO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP0_WO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP0_WO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP0_WO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP0_WO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP0_WO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP0_WO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP0_WO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP3_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP3_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP3_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP3_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP3_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP3_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP3_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP3_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP3_SCOMFSI0(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP3_SCOMFSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP3_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP3_SCOMFSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP3_SCOMFSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP3_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP3_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP3_SCOMFSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SCI2CM(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SCI2CM;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SCI2CM(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SCI2CM;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SCI2CM, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SCI2CM(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SCI2CM));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SCI2CM, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SCRSIM4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SCRSIM4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SCRSIM4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SCRSIM4;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SCRSIM4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SCRSIM4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SCRSIM4));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SCRSIM4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SOML(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SOML;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SOML(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SOML;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SOML, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SOML(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SOML));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SOML, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SRSIC4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SRSIC4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SRSIC4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SRSIC4;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SRSIC4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SRSIC4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SRSIC4));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SRSIC4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FSI1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FIRST_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FIRST_ERROR,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FIRST_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FIRST_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FIRST_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FIRST_ERROR,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FIRST_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FIRST_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FIRST_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FIRST_ERROR,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FIRST_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FIRST_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_FRST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_FRST,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_FRST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_FRST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_FRST(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_FRST,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_FRST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_FRST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_FRST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_FRST,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_FRST_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_FRST chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_ACTUAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_ACTUAL_ERROR,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_ACTUAL_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_ACTUAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_ACTUAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_ACTUAL_ERROR,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_ACTUAL_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_ACTUAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_ACTUAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_ACTUAL_ERROR,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_ACTUAL_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_ACTUAL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_ACT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_ACT,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_ACT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_ACT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_ACT,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_ACT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_ACT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_ACT,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_ACT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_FSI1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_FSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_FSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_FSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_FSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_FSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_WO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_FSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_WO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_WO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_WO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_WO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_WO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_WO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_WO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_WO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_GENERAL_RESET_6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_WO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_GENERAL_RESET_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_GENERAL_RESET_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_GENERAL_RESET_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_WO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_GENERAL_RESET_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_GENERAL_RESET_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_GENERAL_RESET_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_WO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_GENERAL_RESET_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_GENERAL_RESET_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_GENERAL_RESET_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_WO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_GENERAL_RESET_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_GENERAL_RESET_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_GENERAL_RESET_6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_WO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_GENERAL_RESET_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_GENERAL_RESET_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_GENERAL_RESET_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_WO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_GENERAL_RESET_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_GENERAL_RESET_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_ERROR_RESET_6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_WO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_ERROR_RESET_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_ERROR_RESET_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_ERROR_RESET_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_WO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_ERROR_RESET_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_ERROR_RESET_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_ERROR_RESET_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_WO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_ERROR_RESET_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_ERROR_RESET_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_ERROR_RESET_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_WO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_ERROR_RESET_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_ERROR_RESET_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_ERROR_RESET_6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_WO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_ERROR_RESET_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_ERROR_RESET_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_ERROR_RESET_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_WO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_ERROR_RESET_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_ERROR_RESET_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP5_FSI1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP5_FSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP5_FSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP5_FSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP5_FSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP5_FSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP5_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP5_SCOMFSI1));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP5_FSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP5_SCOMFSI1(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP5_SCOMFSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP5_SCOMFSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP5_SCOMFSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP5_SCOMFSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP5_SCOMFSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP5_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP5_SCOMFSI1));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP5_SCOMFSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_SI1M(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SI1M;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_SI1M(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SI1M;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SI1M, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_SI1M(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SI1M));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SI1M, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_SI2S(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SI2S;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_SI2S(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SI2S;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SI2S, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_SI2S(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SI2S));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SI2S, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_SLASTD_SRES(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SLASTD_SRES;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_SLASTD_SRES(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SLASTD_SRES;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SLASTD_SRES, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_SLASTD_SRES(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SLASTD_SRES));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SLASTD_SRES, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_SSMBR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SSMBR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_SSMBR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SSMBR;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SSMBR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_SSMBR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SSMBR));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SSMBR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_BASE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_BASE,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_BASE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_BASE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_BASE,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_BASE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_BASE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_BASE,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_BASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_BASE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_MASK,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_MASK,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_MASK,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_RESERVED,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_RESERVED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_RESERVED,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_RESERVED,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_MEMORY_MAPPING_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CLOCK_CONFIG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CLOCK_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CLOCK_CONFIG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CLOCK_CONFIG;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CLOCK_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CLOCK_CONFIG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CLOCK_CONFIG));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CLOCK_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CONFIG1(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CONFIG1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CONFIG1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CONFIG1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CONFIG1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CONFIG1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CONFIG1));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CONFIG1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CONFIG1_CONFIG1_Q(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CONFIG1));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CONFIG1_CONFIG1_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CONFIG1_CONFIG1_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CONFIG1_CONFIG1_Q chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CONFIG1_CONFIG1_Q(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CONFIG1));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CONFIG1_CONFIG1_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CONFIG1_CONFIG1_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CONFIG1_CONFIG1_Q chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CONFIG1_CONFIG1_Q(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CONFIG1));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CONFIG1_CONFIG1_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CONFIG1_CONFIG1_Q_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_CONFIG1_CONFIG1_Q chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_CAMDATA1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_CAMDATA1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_CAMDATA1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_CAMDATA1;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_CAMDATA1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_CAMDATA1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_CAMDATA1));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_CAMDATA1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_CAMDATA1_CAM_DISPLAY_REG_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_CAMDATA1));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_CAMDATA1_CAM_DISPLAY_REG_1,
           VAS_VA_RG_SCF_CAMDATA1_CAM_DISPLAY_REG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_CAMDATA1_CAM_DISPLAY_REG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_CAMDATA1_CAM_DISPLAY_REG_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_CAMDATA1));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_CAMDATA1_CAM_DISPLAY_REG_1,
           VAS_VA_RG_SCF_CAMDATA1_CAM_DISPLAY_REG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_CAMDATA1_CAM_DISPLAY_REG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_CAMDATA1_CAM_DISPLAY_REG_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_CAMDATA1));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_CAMDATA1_CAM_DISPLAY_REG_1,
           VAS_VA_RG_SCF_CAMDATA1_CAM_DISPLAY_REG_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_CAMDATA1_CAM_DISPLAY_REG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_DBGCONT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_DBGCONT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_DBGCONT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_DBGCONT;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_DBGCONT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_DBGCONT(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGCONT));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_DBGCONT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGCONT_TRACE_BUS_BITS_0_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGCONT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGCONT_TRACE_BUS_BITS_0_63,
           VAS_VA_RG_SCF_DBGCONT_TRACE_BUS_BITS_0_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGCONT_TRACE_BUS_BITS_0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_DBGCONT_TRACE_BUS_BITS_0_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGCONT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_DBGCONT_TRACE_BUS_BITS_0_63,
           VAS_VA_RG_SCF_DBGCONT_TRACE_BUS_BITS_0_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGCONT_TRACE_BUS_BITS_0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_DBGCONT_TRACE_BUS_BITS_0_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_DBGCONT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_DBGCONT_TRACE_BUS_BITS_0_63,
           VAS_VA_RG_SCF_DBGCONT_TRACE_BUS_BITS_0_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_DBGCONT_TRACE_BUS_BITS_0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_MMIODATA(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_MMIODATA;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_MMIODATA(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_MMIODATA;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_MMIODATA, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_MMIODATA(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIODATA));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_MMIODATA, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MMIODATA_MMIO_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIODATA));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MMIODATA_MMIO_DATA,
           VAS_VA_RG_SCF_MMIODATA_MMIO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_MMIODATA_MMIO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MMIODATA_MMIO_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIODATA));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MMIODATA_MMIO_DATA,
           VAS_VA_RG_SCF_MMIODATA_MMIO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_MMIODATA_MMIO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_MMIODATA_MMIO_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIODATA));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_MMIODATA_MMIO_DATA,
           VAS_VA_RG_SCF_MMIODATA_MMIO_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_MMIODATA_MMIO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
