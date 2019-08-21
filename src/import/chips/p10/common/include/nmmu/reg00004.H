/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/nmmu/reg00004.H $         */
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

#ifndef __NMMU_REG00004_H_
#define __NMMU_REG00004_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace nmmu
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CFG_NMMU_CTL_SM(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CFG_NMMU_CTL_SM;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CFG_NMMU_CTL_SM(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CFG_NMMU_CTL_SM;
#endif
    return fapi2::getScom(i_target, CFG_NMMU_CTL_SM, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CFG_NMMU_CTL_SM(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return fapi2::putScom(i_target, CFG_NMMU_CTL_SM, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_TWSM_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_TWSM_DIS,
           CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_TWSM_DIS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_TWSM_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_TWSM_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_TWSM_DIS,
           CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_TWSM_DIS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_TWSM_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_TWSM_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_TWSM_DIS,
           CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_TWSM_DIS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_TWSM_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_CKINSM_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_CKINSM_DIS,
           CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_CKINSM_DIS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_CKINSM_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_CKINSM_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_CKINSM_DIS,
           CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_CKINSM_DIS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_CKINSM_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_CKINSM_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_CKINSM_DIS,
           CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_CKINSM_DIS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_CKINSM_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_INV_SINGLE_THREAD_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_INV_SINGLE_THREAD_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_INV_SINGLE_THREAD_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_INV_SINGLE_THREAD_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_INV_SINGLE_THREAD_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_INV_SINGLE_THREAD_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_INV_SINGLE_THREAD_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_INV_SINGLE_THREAD_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_INV_SINGLE_THREAD_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_INV_SINGLE_THREAD_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_INV_SINGLE_THREAD_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_INV_SINGLE_THREAD_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_INV_SINGLE_THREAD_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_INV_SINGLE_THREAD_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_INV_SINGLE_THREAD_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_INV_SINGLE_THREAD_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_INV_SINGLE_THREAD_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_INV_SINGLE_THREAD_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_CXT_CAC_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_CXT_CAC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_CXT_CAC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_CXT_CAC_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_CXT_CAC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_CXT_CAC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_CXT_CAC_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_CXT_CAC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_CXT_CAC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_CXT_CAC_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_CXT_CAC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_CXT_CAC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_CXT_CAC_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_CXT_CAC_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_CXT_CAC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_CXT_CAC_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_CXT_CAC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_CXT_CAC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_RESERVED_22_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_RESERVED_22_23,
           CFG_NMMU_CTL_SM_RESERVED_22_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_22_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_RESERVED_22_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_RESERVED_22_23,
           CFG_NMMU_CTL_SM_RESERVED_22_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_22_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_RESERVED_22_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_RESERVED_22_23,
           CFG_NMMU_CTL_SM_RESERVED_22_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_22_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS487_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS487_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS487_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS487_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS487_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS487_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS487_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS487_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS487_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS487_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS487_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS487_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS487_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS487_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS487_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS487_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS487_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS487_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_RESERVED_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_RESERVED_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_RESERVED_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_RESERVED_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_RESERVED_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_RESERVED_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_RESERVED_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_RESERVED_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_RESERVED_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_RESERVED_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_RESERVED_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_RESERVED_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS526_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS526_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS526_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS526_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS526_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS526_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS526_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS526_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS526_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS526_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS526_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS526_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS526_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS526_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS526_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS526_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS526_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_SM_ISS526_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_RESERVED_27_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_RESERVED_27_29,
           CFG_NMMU_CTL_SM_RESERVED_27_29_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_27_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_RESERVED_27_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_RESERVED_27_29,
           CFG_NMMU_CTL_SM_RESERVED_27_29_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_27_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_RESERVED_27_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_RESERVED_27_29,
           CFG_NMMU_CTL_SM_RESERVED_27_29_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_27_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_DYN_ST_FREQ_MULT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_DYN_ST_FREQ_MULT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_DYN_ST_FREQ_MULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_DYN_ST_FREQ_MULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_DYN_ST_FREQ_MULT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_DYN_ST_FREQ_MULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_DYN_ST_FREQ_MULT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_DYN_ST_FREQ_MULT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_DYN_ST_FREQ_MULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_DYN_ST_FREQ_MULT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_DYN_ST_FREQ_MULT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_DYN_ST_FREQ_MULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_DYN_ST_FREQ_MULT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_DYN_ST_FREQ_MULT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_DYN_ST_FREQ_MULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_DYN_ST_FREQ_MULT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_DYN_ST_FREQ_MULT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_DYN_ST_FREQ_MULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_MPSS_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_MPSS_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_MPSS_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_MPSS_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_MPSS_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_MPSS_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_MPSS_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_MPSS_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_MPSS_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_MPSS_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_MPSS_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_MPSS_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_MPSS_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_MPSS_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_MPSS_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_MPSS_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_MPSS_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_MPSS_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_CNT_THRESH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_CNT_THRESH,
           CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_CNT_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_CNT_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_CNT_THRESH(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_CNT_THRESH,
           CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_CNT_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_CNT_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_CNT_THRESH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_CNT_THRESH,
           CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_CNT_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_CNT_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_HPT_SAO_FOLD_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_HPT_SAO_FOLD_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_HPT_SAO_FOLD_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_HPT_SAO_FOLD_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_HPT_SAO_FOLD_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_HPT_SAO_FOLD_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_HPT_SAO_FOLD_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_HPT_SAO_FOLD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_HPT_SAO_FOLD_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_HPT_SAO_FOLD_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_HPT_SAO_FOLD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_HPT_SAO_FOLD_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_HPT_SAO_FOLD_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_HPT_SAO_FOLD_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_HPT_SAO_FOLD_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_HPT_SAO_FOLD_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_HPT_SAO_FOLD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_HPT_SAO_FOLD_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_SAO_FOLD_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_SAO_FOLD_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_SAO_FOLD_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_SAO_FOLD_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_SAO_FOLD_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_SAO_FOLD_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_SAO_FOLD_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_SAO_FOLD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_SAO_FOLD_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_SAO_FOLD_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_SAO_FOLD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_SAO_FOLD_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_SAO_FOLD_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_SAO_FOLD_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_SAO_FOLD_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_SAO_FOLD_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_SAO_FOLD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_SAO_FOLD_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_NIO_FOLD_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_NIO_FOLD_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_NIO_FOLD_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_NIO_FOLD_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_NIO_FOLD_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_NIO_FOLD_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_NIO_FOLD_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_NIO_FOLD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_NIO_FOLD_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_NIO_FOLD_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_NIO_FOLD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_NIO_FOLD_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_NIO_FOLD_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_NIO_FOLD_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_NIO_FOLD_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_NIO_FOLD_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_NIO_FOLD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_NIO_FOLD_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_TIO_FOLD_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_TIO_FOLD_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_TIO_FOLD_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_TIO_FOLD_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_TIO_FOLD_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_TIO_FOLD_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_TIO_FOLD_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_TIO_FOLD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_TIO_FOLD_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_TIO_FOLD_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_TIO_FOLD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_TIO_FOLD_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_TIO_FOLD_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_TIO_FOLD_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_TIO_FOLD_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_TIO_FOLD_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_TIO_FOLD_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_ATT_RDX_TIO_FOLD_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_UPRC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_UPRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_UPRC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_UPRC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_UPRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_UPRC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_UPRC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_UPRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_UPRC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_UPRC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_UPRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_UPRC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_UPRC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_UPRC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_UPRC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_UPRC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_UPRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_UPRC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_PF(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_PF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_PF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_PF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_PF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_PF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_PF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_PF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_PF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_PF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_PF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_PF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_PF(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_PF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_PF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_PF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_PF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_ABRT_IF_PF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_RESERVED_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_RESERVED_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_RESERVED_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_RESERVED_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_RESERVED_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_RESERVED_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_RESERVED_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_RESERVED_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_RESERVED_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_RESERVED_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_RESERVED_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_RESERVED_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_RESERVED_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_RESERVED_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_RESERVED_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_RESERVED_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_RESERVED_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_RESERVED_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_RESERVED_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_RESERVED_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_RESERVED_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_RESERVED_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_RESERVED_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_RESERVED_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_RESERVED_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_RESERVED_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_RESERVED_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_RESERVED_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_RESERVED_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_RESERVED_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_RESERVED_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_RESERVED_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_RESERVED_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_RESERVED_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_RESERVED_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_RESERVED_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_RESERVED_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_RESERVED_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_RESERVED_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_RESERVED_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_RESERVED_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_RESERVED_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_RESERVED_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_RESERVED_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_RESERVED_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_RESERVED_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_RESERVED_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_RESERVED_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_RESERVED_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_PDE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_PDE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_PDE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_PDE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_PDE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_PDE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_PDE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_PDE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_PDE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_PDE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_PDE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_PDE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_PDE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_PDE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_PDE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_PDE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_PDE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_LCO_RDX_PDE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_PWC_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_PWC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_PWC_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_PWC_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_PWC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_PWC_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_PWC_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_PWC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_PWC_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_PWC_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_PWC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_PWC_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_PWC_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_PWC_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_PWC_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_PWC_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_PWC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_PWC_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_TLB_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_TLB_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_TLB_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_TLB_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_TLB_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_TLB_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_TLB_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_TLB_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_TLB_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_TLB_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_TLB_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_TLB_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_TLB_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_TLB_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_TLB_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_TLB_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_TLB_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_INT_TLB_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_SPLIT_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_SPLIT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_SPLIT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_SPLIT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_SPLIT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_SPLIT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_SPLIT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_SPLIT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_SPLIT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_SPLIT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_SPLIT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_SPLIT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_SPLIT_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_SPLIT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_SPLIT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_SPLIT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_SPLIT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_SPLIT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_VA_HASH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_VA_HASH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_VA_HASH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_VA_HASH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_VA_HASH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_VA_HASH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_VA_HASH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_VA_HASH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_VA_HASH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_VA_HASH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_VA_HASH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_VA_HASH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_VA_HASH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_VA_HASH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_VA_HASH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_VA_HASH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_VA_HASH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_RDX_PWC_VA_HASH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_OVERLAP_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_OVERLAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_OVERLAP_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_OVERLAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_OVERLAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_OVERLAP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_OVERLAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_OVERLAP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_OVERLAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_OVERLAP_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_OVERLAP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_OVERLAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_OVERLAP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_OVERLAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_OVERLAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_PTE_UPD_INTR_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_PTE_UPD_INTR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_PTE_UPD_INTR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_PTE_UPD_INTR_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_PTE_UPD_INTR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_PTE_UPD_INTR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_PTE_UPD_INTR_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_PTE_UPD_INTR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_PTE_UPD_INTR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_PTE_UPD_INTR_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_PTE_UPD_INTR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_PTE_UPD_INTR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_PTE_UPD_INTR_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_PTE_UPD_INTR_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_PTE_UPD_INTR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_PTE_UPD_INTR_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_PTE_UPD_INTR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_TW_PTE_UPD_INTR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_PACING_CNT_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_PACING_CNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_PACING_CNT_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_PACING_CNT_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.insertFromRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_PACING_CNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_PACING_CNT_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_PACING_CNT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.setBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_PACING_CNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_PACING_CNT_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_PACING_CNT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return o_data.clearBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_PACING_CNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_PACING_CNT_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_PACING_CNT_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.extractToRight<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_PACING_CNT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_PACING_CNT_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_PACING_CNT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_CTL_SM));
#endif
    return i_data.getBit<CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_PACING_CNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_CTL_SM_MM_CFG_NMMU_CTL_NCU_SNP_TLBIE_PACING_CNT_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG;
#endif
    return fapi2::getScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG));
#endif
    return fapi2::putScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_CONFIG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_CONFIG,
           FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_CONFIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_CONFIG,
           FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_CONFIG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_CONFIG,
           FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_CONFIG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_MIN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_MIN,
           FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_MIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_MIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_MIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_MIN,
           FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_MIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_MIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_MIN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_MIN,
           FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_MIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_TARG_MIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_CRED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_CRED_MASK,
           FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_CRED_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_CRED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_CRED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_CRED_MASK,
           FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_CRED_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_CRED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_CRED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_CRED_MASK,
           FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_CRED_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_LCO_CONFIG_REG_CRED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
