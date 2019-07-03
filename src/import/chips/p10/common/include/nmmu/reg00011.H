/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/nmmu/reg00011.H $         */
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

#ifndef __NMMU_REG00011_H_
#define __NMMU_REG00011_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace nmmu
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CFG_NMMU_XLAT_CTL_REG0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CFG_NMMU_XLAT_CTL_REG0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CFG_NMMU_XLAT_CTL_REG0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CFG_NMMU_XLAT_CTL_REG0;
#endif
    return fapi2::getScom(i_target, CFG_NMMU_XLAT_CTL_REG0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CFG_NMMU_XLAT_CTL_REG0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CFG_NMMU_XLAT_CTL_REG0));
#endif
    return fapi2::putScom(i_target, CFG_NMMU_XLAT_CTL_REG0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_XLAT_CTL_REG0_MM_CFG_XLAT_CTL_HRMOR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_XLAT_CTL_REG0));
#endif
    return o_data.insertFromRight<CFG_NMMU_XLAT_CTL_REG0_MM_CFG_XLAT_CTL_HRMOR,
           CFG_NMMU_XLAT_CTL_REG0_MM_CFG_XLAT_CTL_HRMOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_XLAT_CTL_REG0_MM_CFG_XLAT_CTL_HRMOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CFG_NMMU_XLAT_CTL_REG0_MM_CFG_XLAT_CTL_HRMOR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_XLAT_CTL_REG0));
#endif
    return o_data.insertFromRight<CFG_NMMU_XLAT_CTL_REG0_MM_CFG_XLAT_CTL_HRMOR,
           CFG_NMMU_XLAT_CTL_REG0_MM_CFG_XLAT_CTL_HRMOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_XLAT_CTL_REG0_MM_CFG_XLAT_CTL_HRMOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CFG_NMMU_XLAT_CTL_REG0_MM_CFG_XLAT_CTL_HRMOR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CFG_NMMU_XLAT_CTL_REG0));
#endif
    return i_data.extractToRight<CFG_NMMU_XLAT_CTL_REG0_MM_CFG_XLAT_CTL_HRMOR,
           CFG_NMMU_XLAT_CTL_REG0_MM_CFG_XLAT_CTL_HRMOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CFG_NMMU_XLAT_CTL_REG0_MM_CFG_XLAT_CTL_HRMOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0;
#endif
    return fapi2::getScom(i_target, FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0));
#endif
    return fapi2::putScom(i_target, FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63,
           FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63,
           FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63,
           FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FIR1_WOF_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR1_WOF_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FIR1_WOF_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FIR1_WOF_REG;
#endif
    return fapi2::getScom(i_target, FIR1_WOF_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FIR1_WOF_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FIR1_WOF_REG));
#endif
    return fapi2::putScom(i_target, FIR1_WOF_REG, i_data);
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
