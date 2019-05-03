/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/nmmu/reg00013.H $         */
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

#ifndef __NMMU_REG00013_H_
#define __NMMU_REG00013_H_

namespace scomt
{
namespace nmmu
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CFG_NMMU_XLAT_CTL_REG1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CFG_NMMU_XLAT_CTL_REG1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CFG_NMMU_XLAT_CTL_REG1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CFG_NMMU_XLAT_CTL_REG1;
#endif
    return fapi2::getScom(i_target, CFG_NMMU_XLAT_CTL_REG1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CFG_NMMU_XLAT_CTL_REG1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CFG_NMMU_XLAT_CTL_REG1));
#endif
    return fapi2::putScom(i_target, CFG_NMMU_XLAT_CTL_REG1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_XLAT_CTL_REG1));
#endif
    return o_data.insertFromRight<CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR,
           CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_XLAT_CTL_REG1));
#endif
    return o_data.insertFromRight<CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR,
           CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_XLAT_CTL_REG1));
#endif
    return i_data.extractToRight<CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR,
           CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_XLAT_CTL_REG1_MM_CFG_XLAT_CTL_PTCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1;
#endif
    return fapi2::getScom(i_target, FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1));
#endif
    return fapi2::putScom(i_target, FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87,
           FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87,
           FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87,
           FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_1_NX_DEBUG_SNAPSHOT_B64_87 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FIR1_ACTION0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR1_ACTION0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FIR1_ACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR1_ACTION0_REG;
#endif
    return fapi2::getScom(i_target, FIR1_ACTION0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FIR1_ACTION0_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FIR1_ACTION0_REG));
#endif
    return fapi2::putScom(i_target, FIR1_ACTION0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_FIR1_ACTION0_REG_MM_FIR1_ACTION0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_ACTION0_REG));
#endif
    return o_data.insertFromRight<FIR1_ACTION0_REG_MM_FIR1_ACTION0,
           FIR1_ACTION0_REG_MM_FIR1_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_ACTION0_REG_MM_FIR1_ACTION0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_ACTION0_REG_MM_FIR1_ACTION0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_ACTION0_REG));
#endif
    return o_data.insertFromRight<FIR1_ACTION0_REG_MM_FIR1_ACTION0,
           FIR1_ACTION0_REG_MM_FIR1_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_ACTION0_REG_MM_FIR1_ACTION0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_ACTION0_REG_MM_FIR1_ACTION0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_ACTION0_REG));
#endif
    return i_data.extractToRight<FIR1_ACTION0_REG_MM_FIR1_ACTION0,
           FIR1_ACTION0_REG_MM_FIR1_ACTION0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_ACTION0_REG_MM_FIR1_ACTION0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FIR1_ACTION1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR1_ACTION1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FIR1_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR1_ACTION1_REG;
#endif
    return fapi2::getScom(i_target, FIR1_ACTION1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FIR1_ACTION1_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FIR1_ACTION1_REG));
#endif
    return fapi2::putScom(i_target, FIR1_ACTION1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_FIR1_ACTION1_REG_MM_FIR1_ACTION1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_ACTION1_REG));
#endif
    return o_data.insertFromRight<FIR1_ACTION1_REG_MM_FIR1_ACTION1,
           FIR1_ACTION1_REG_MM_FIR1_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_ACTION1_REG_MM_FIR1_ACTION1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FIR1_ACTION1_REG_MM_FIR1_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_ACTION1_REG));
#endif
    return o_data.insertFromRight<FIR1_ACTION1_REG_MM_FIR1_ACTION1,
           FIR1_ACTION1_REG_MM_FIR1_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_ACTION1_REG_MM_FIR1_ACTION1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FIR1_ACTION1_REG_MM_FIR1_ACTION1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FIR1_ACTION1_REG));
#endif
    return i_data.extractToRight<FIR1_ACTION1_REG_MM_FIR1_ACTION1,
           FIR1_ACTION1_REG_MM_FIR1_ACTION1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FIR1_ACTION1_REG_MM_FIR1_ACTION1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NMMU_ERR_INJ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NMMU_ERR_INJ;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NMMU_ERR_INJ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NMMU_ERR_INJ;
#endif
    return fapi2::getScom(i_target, NMMU_ERR_INJ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NMMU_ERR_INJ(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return fapi2::putScom(i_target, NMMU_ERR_INJ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_DIR_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_TLB_DIR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_DIR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_DIR_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_TLB_DIR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_DIR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_DIR_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_TLB_DIR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_DIR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_TLB_DIR_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_TLB_DIR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_DIR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_TLB_DIR_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_TLB_DIR_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_DIR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_TLB_DIR_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_TLB_DIR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_DIR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_DIR_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_TLB_DIR_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_DIR_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_DIR_SNGL_SHOT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_TLB_DIR_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_DIR_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_DIR_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_TLB_DIR_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_DIR_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_TLB_DIR_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_TLB_DIR_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_DIR_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_TLB_DIR_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_TLB_DIR_SNGL_SHOT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_DIR_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_TLB_DIR_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_TLB_DIR_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_DIR_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_DIR_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_TLB_DIR_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_DIR_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_DIR_OVERLAP_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_TLB_DIR_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_DIR_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_DIR_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_TLB_DIR_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_DIR_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_TLB_DIR_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_TLB_DIR_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_DIR_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_TLB_DIR_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_TLB_DIR_OVERLAP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_DIR_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_TLB_DIR_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_TLB_DIR_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_DIR_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_DIR_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_TLB_DIR_MULT_SEL,
           NMMU_ERR_INJ_TLB_DIR_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_DIR_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_DIR_MULT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_TLB_DIR_MULT_SEL,
           NMMU_ERR_INJ_TLB_DIR_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_DIR_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_TLB_DIR_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_TLB_DIR_MULT_SEL,
           NMMU_ERR_INJ_TLB_DIR_MULT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_DIR_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_CAC_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_TLB_CAC_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_CAC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_CAC_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_TLB_CAC_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_CAC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_CAC_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_TLB_CAC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_CAC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_TLB_CAC_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_TLB_CAC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_CAC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_TLB_CAC_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_TLB_CAC_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_CAC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_TLB_CAC_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_TLB_CAC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_CAC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_CAC_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_TLB_CAC_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_CAC_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_CAC_SNGL_SHOT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_TLB_CAC_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_CAC_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_CAC_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_TLB_CAC_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_CAC_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_TLB_CAC_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_TLB_CAC_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_CAC_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_TLB_CAC_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_TLB_CAC_SNGL_SHOT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_CAC_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_TLB_CAC_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_TLB_CAC_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_CAC_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_CAC_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_TLB_CAC_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_CAC_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_CAC_OVERLAP_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_TLB_CAC_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_CAC_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_CAC_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_TLB_CAC_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_CAC_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_TLB_CAC_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_TLB_CAC_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_CAC_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_TLB_CAC_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_TLB_CAC_OVERLAP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_CAC_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_TLB_CAC_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_TLB_CAC_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_CAC_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_CAC_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_TLB_CAC_MULT_SEL,
           NMMU_ERR_INJ_TLB_CAC_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_CAC_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_CAC_MULT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_TLB_CAC_MULT_SEL,
           NMMU_ERR_INJ_TLB_CAC_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_CAC_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_TLB_CAC_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_TLB_CAC_MULT_SEL,
           NMMU_ERR_INJ_TLB_CAC_MULT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_CAC_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_LRU_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_TLB_LRU_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_LRU_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_LRU_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_TLB_LRU_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_LRU_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_LRU_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_TLB_LRU_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_LRU_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_TLB_LRU_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_TLB_LRU_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_LRU_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_TLB_LRU_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_TLB_LRU_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_LRU_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_TLB_LRU_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_TLB_LRU_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_LRU_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_LRU_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_TLB_LRU_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_LRU_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_LRU_SNGL_SHOT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_TLB_LRU_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_LRU_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_LRU_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_TLB_LRU_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_LRU_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_TLB_LRU_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_TLB_LRU_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_LRU_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_TLB_LRU_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_TLB_LRU_SNGL_SHOT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_LRU_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_TLB_LRU_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_TLB_LRU_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_LRU_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_LRU_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_TLB_LRU_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_LRU_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_LRU_OVERLAP_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_TLB_LRU_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_LRU_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_LRU_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_TLB_LRU_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_LRU_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_TLB_LRU_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_TLB_LRU_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_LRU_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_TLB_LRU_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_TLB_LRU_OVERLAP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_LRU_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_TLB_LRU_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_TLB_LRU_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_LRU_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_LRU_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_TLB_LRU_MULT_SEL,
           NMMU_ERR_INJ_TLB_LRU_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_LRU_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_TLB_LRU_MULT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_TLB_LRU_MULT_SEL,
           NMMU_ERR_INJ_TLB_LRU_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_LRU_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_TLB_LRU_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_TLB_LRU_MULT_SEL,
           NMMU_ERR_INJ_TLB_LRU_MULT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_TLB_LRU_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_PWC_DIR_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_PWC_DIR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_DIR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_PWC_DIR_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_PWC_DIR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_DIR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_PWC_DIR_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_PWC_DIR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_DIR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_PWC_DIR_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_PWC_DIR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_DIR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_PWC_DIR_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_PWC_DIR_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_DIR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_PWC_DIR_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_PWC_DIR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_DIR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_PWC_DIR_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_PWC_DIR_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_DIR_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_PWC_DIR_SNGL_SHOT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_PWC_DIR_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_DIR_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_PWC_DIR_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_PWC_DIR_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_DIR_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_PWC_DIR_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_PWC_DIR_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_DIR_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_PWC_DIR_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_PWC_DIR_SNGL_SHOT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_DIR_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_PWC_DIR_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_PWC_DIR_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_DIR_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_PWC_DIR_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_PWC_DIR_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_DIR_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_PWC_DIR_OVERLAP_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_PWC_DIR_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_DIR_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_PWC_DIR_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_PWC_DIR_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_DIR_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_PWC_DIR_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_PWC_DIR_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_DIR_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_PWC_DIR_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_PWC_DIR_OVERLAP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_DIR_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_PWC_DIR_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_PWC_DIR_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_DIR_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_PWC_DIR_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_PWC_DIR_MULT_SEL,
           NMMU_ERR_INJ_PWC_DIR_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_DIR_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_PWC_DIR_MULT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_PWC_DIR_MULT_SEL,
           NMMU_ERR_INJ_PWC_DIR_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_DIR_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_PWC_DIR_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_PWC_DIR_MULT_SEL,
           NMMU_ERR_INJ_PWC_DIR_MULT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_DIR_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_PWC_CAC_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_PWC_CAC_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_CAC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_PWC_CAC_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_PWC_CAC_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_CAC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_PWC_CAC_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_PWC_CAC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_CAC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_PWC_CAC_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_PWC_CAC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_CAC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_PWC_CAC_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_PWC_CAC_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_CAC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_PWC_CAC_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_PWC_CAC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_CAC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_PWC_CAC_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_PWC_CAC_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_CAC_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_PWC_CAC_SNGL_SHOT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_PWC_CAC_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_CAC_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_PWC_CAC_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_PWC_CAC_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_CAC_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_PWC_CAC_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_PWC_CAC_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_CAC_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_PWC_CAC_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_PWC_CAC_SNGL_SHOT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_CAC_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_PWC_CAC_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_PWC_CAC_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_CAC_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_PWC_CAC_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_PWC_CAC_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_CAC_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_PWC_CAC_OVERLAP_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_PWC_CAC_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_CAC_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_PWC_CAC_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_PWC_CAC_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_CAC_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_PWC_CAC_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_PWC_CAC_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_CAC_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_PWC_CAC_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_PWC_CAC_OVERLAP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_CAC_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_PWC_CAC_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_PWC_CAC_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_CAC_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_PWC_CAC_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_PWC_CAC_MULT_SEL,
           NMMU_ERR_INJ_PWC_CAC_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_CAC_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_PWC_CAC_MULT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_PWC_CAC_MULT_SEL,
           NMMU_ERR_INJ_PWC_CAC_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_CAC_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_PWC_CAC_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_PWC_CAC_MULT_SEL,
           NMMU_ERR_INJ_PWC_CAC_MULT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_PWC_CAC_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_DIR_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_SLB_DIR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_DIR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_DIR_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_SLB_DIR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_DIR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_DIR_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_SLB_DIR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_DIR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_SLB_DIR_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_SLB_DIR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_DIR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_SLB_DIR_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_SLB_DIR_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_DIR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_SLB_DIR_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_SLB_DIR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_DIR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_DIR_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_SLB_DIR_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_DIR_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_DIR_SNGL_SHOT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_SLB_DIR_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_DIR_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_DIR_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_SLB_DIR_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_DIR_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_SLB_DIR_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_SLB_DIR_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_DIR_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_SLB_DIR_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_SLB_DIR_SNGL_SHOT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_DIR_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_SLB_DIR_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_SLB_DIR_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_DIR_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_DIR_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_SLB_DIR_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_DIR_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_DIR_OVERLAP_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_SLB_DIR_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_DIR_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_DIR_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_SLB_DIR_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_DIR_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_SLB_DIR_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_SLB_DIR_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_DIR_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_SLB_DIR_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_SLB_DIR_OVERLAP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_DIR_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_SLB_DIR_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_SLB_DIR_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_DIR_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_DIR_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_SLB_DIR_MULT_SEL,
           NMMU_ERR_INJ_SLB_DIR_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_DIR_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_DIR_MULT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_SLB_DIR_MULT_SEL,
           NMMU_ERR_INJ_SLB_DIR_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_DIR_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_SLB_DIR_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_SLB_DIR_MULT_SEL,
           NMMU_ERR_INJ_SLB_DIR_MULT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_DIR_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_CAC_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_SLB_CAC_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_CAC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_CAC_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_SLB_CAC_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_CAC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_CAC_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_SLB_CAC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_CAC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_SLB_CAC_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_SLB_CAC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_CAC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_SLB_CAC_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_SLB_CAC_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_CAC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_SLB_CAC_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_SLB_CAC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_CAC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_CAC_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_SLB_CAC_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_CAC_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_CAC_SNGL_SHOT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_SLB_CAC_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_CAC_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_CAC_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_SLB_CAC_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_CAC_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_SLB_CAC_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_SLB_CAC_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_CAC_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_SLB_CAC_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_SLB_CAC_SNGL_SHOT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_CAC_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_SLB_CAC_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_SLB_CAC_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_CAC_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_CAC_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_SLB_CAC_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_CAC_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_CAC_OVERLAP_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_SLB_CAC_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_CAC_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_CAC_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_SLB_CAC_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_CAC_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_SLB_CAC_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_SLB_CAC_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_CAC_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_SLB_CAC_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_SLB_CAC_OVERLAP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_CAC_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_SLB_CAC_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_SLB_CAC_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_CAC_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_CAC_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_SLB_CAC_MULT_SEL,
           NMMU_ERR_INJ_SLB_CAC_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_CAC_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_CAC_MULT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_SLB_CAC_MULT_SEL,
           NMMU_ERR_INJ_SLB_CAC_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_CAC_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_SLB_CAC_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_SLB_CAC_MULT_SEL,
           NMMU_ERR_INJ_SLB_CAC_MULT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_CAC_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_LRU_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_SLB_LRU_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_LRU_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_LRU_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_SLB_LRU_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_LRU_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_LRU_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_SLB_LRU_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_LRU_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_SLB_LRU_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_SLB_LRU_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_LRU_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_SLB_LRU_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_SLB_LRU_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_LRU_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_SLB_LRU_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_SLB_LRU_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_LRU_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_LRU_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_SLB_LRU_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_LRU_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_LRU_SNGL_SHOT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_SLB_LRU_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_LRU_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_LRU_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_SLB_LRU_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_LRU_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_SLB_LRU_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_SLB_LRU_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_LRU_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_SLB_LRU_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_SLB_LRU_SNGL_SHOT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_LRU_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_SLB_LRU_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_SLB_LRU_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_LRU_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_LRU_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_SLB_LRU_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_LRU_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_LRU_OVERLAP_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_SLB_LRU_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_LRU_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_LRU_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_SLB_LRU_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_LRU_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_SLB_LRU_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_SLB_LRU_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_LRU_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_SLB_LRU_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_SLB_LRU_OVERLAP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_LRU_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_SLB_LRU_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_SLB_LRU_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_LRU_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_LRU_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_SLB_LRU_MULT_SEL,
           NMMU_ERR_INJ_SLB_LRU_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_LRU_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_SLB_LRU_MULT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_SLB_LRU_MULT_SEL,
           NMMU_ERR_INJ_SLB_LRU_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_LRU_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_SLB_LRU_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_SLB_LRU_MULT_SEL,
           NMMU_ERR_INJ_SLB_LRU_MULT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_SLB_LRU_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_CXT_DIR_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_CXT_DIR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_DIR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_CXT_DIR_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_CXT_DIR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_DIR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_CXT_DIR_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_CXT_DIR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_DIR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_CXT_DIR_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_CXT_DIR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_DIR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_CXT_DIR_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_CXT_DIR_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_DIR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_CXT_DIR_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_CXT_DIR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_DIR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_CXT_DIR_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_CXT_DIR_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_DIR_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_CXT_DIR_SNGL_SHOT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_CXT_DIR_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_DIR_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_CXT_DIR_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_CXT_DIR_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_DIR_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_CXT_DIR_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_CXT_DIR_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_DIR_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_CXT_DIR_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_CXT_DIR_SNGL_SHOT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_DIR_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_CXT_DIR_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_CXT_DIR_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_DIR_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_CXT_DIR_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_CXT_DIR_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_DIR_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_CXT_DIR_OVERLAP_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_CXT_DIR_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_DIR_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_CXT_DIR_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_CXT_DIR_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_DIR_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_CXT_DIR_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_CXT_DIR_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_DIR_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_CXT_DIR_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_CXT_DIR_OVERLAP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_DIR_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_CXT_DIR_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_CXT_DIR_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_DIR_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_CXT_DIR_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_CXT_DIR_MULT_SEL,
           NMMU_ERR_INJ_CXT_DIR_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_DIR_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_CXT_DIR_MULT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_CXT_DIR_MULT_SEL,
           NMMU_ERR_INJ_CXT_DIR_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_DIR_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_CXT_DIR_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_CXT_DIR_MULT_SEL,
           NMMU_ERR_INJ_CXT_DIR_MULT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_DIR_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_CXT_CAC_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_CXT_CAC_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_CAC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_CXT_CAC_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_CXT_CAC_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_CAC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_CXT_CAC_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_CXT_CAC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_CAC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_CXT_CAC_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_CXT_CAC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_CAC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_CXT_CAC_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_CXT_CAC_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_CAC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_CXT_CAC_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_CXT_CAC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_CAC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_CXT_CAC_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_CXT_CAC_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_CAC_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_CXT_CAC_SNGL_SHOT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_CXT_CAC_SNGL_SHOT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_CAC_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_CXT_CAC_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_CXT_CAC_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_CAC_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_CXT_CAC_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_CXT_CAC_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_CAC_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_CXT_CAC_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_CXT_CAC_SNGL_SHOT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_CAC_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_CXT_CAC_SNGL_SHOT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_CXT_CAC_SNGL_SHOT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_CAC_SNGL_SHOT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_CXT_CAC_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_CXT_CAC_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_CAC_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_CXT_CAC_OVERLAP_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_CXT_CAC_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_CAC_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_CXT_CAC_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.setBit<NMMU_ERR_INJ_CXT_CAC_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_CAC_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NMMU_ERR_INJ_CXT_CAC_OVERLAP_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.clearBit<NMMU_ERR_INJ_CXT_CAC_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_CAC_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_CXT_CAC_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_CXT_CAC_OVERLAP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_CAC_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NMMU_ERR_INJ_CXT_CAC_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.getBit<NMMU_ERR_INJ_CXT_CAC_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_CAC_OVERLAP_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_CXT_CAC_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_CXT_CAC_MULT_SEL,
           NMMU_ERR_INJ_CXT_CAC_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_CAC_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_ERR_INJ_CXT_CAC_MULT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return o_data.insertFromRight<NMMU_ERR_INJ_CXT_CAC_MULT_SEL,
           NMMU_ERR_INJ_CXT_CAC_MULT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_CAC_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_ERR_INJ_CXT_CAC_MULT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_ERR_INJ));
#endif
    return i_data.extractToRight<NMMU_ERR_INJ_CXT_CAC_MULT_SEL,
           NMMU_ERR_INJ_CXT_CAC_MULT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_ERR_INJ_CXT_CAC_MULT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NMMU_PMU0_CTL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NMMU_PMU0_CTL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NMMU_PMU0_CTL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NMMU_PMU0_CTL_REG;
#endif
    return fapi2::getScom(i_target, NMMU_PMU0_CTL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NMMU_PMU0_CTL_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NMMU_PMU0_CTL_REG));
#endif
    return fapi2::putScom(i_target, NMMU_PMU0_CTL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NMMU_PMU0_CTL_REG_MM_PMU0_CTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_PMU0_CTL_REG));
#endif
    return o_data.insertFromRight<NMMU_PMU0_CTL_REG_MM_PMU0_CTL,
           NMMU_PMU0_CTL_REG_MM_PMU0_CTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_PMU0_CTL_REG_MM_PMU0_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_PMU0_CTL_REG_MM_PMU0_CTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_PMU0_CTL_REG));
#endif
    return o_data.insertFromRight<NMMU_PMU0_CTL_REG_MM_PMU0_CTL,
           NMMU_PMU0_CTL_REG_MM_PMU0_CTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_PMU0_CTL_REG_MM_PMU0_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_PMU0_CTL_REG_MM_PMU0_CTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_PMU0_CTL_REG));
#endif
    return i_data.extractToRight<NMMU_PMU0_CTL_REG_MM_PMU0_CTL,
           NMMU_PMU0_CTL_REG_MM_PMU0_CTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_PMU0_CTL_REG_MM_PMU0_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
