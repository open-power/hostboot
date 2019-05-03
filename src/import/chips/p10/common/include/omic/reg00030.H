/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omic/reg00030.H $         */
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

#ifndef __OMIC_REG00030_H_
#define __OMIC_REG00030_H_

namespace scomt
{
namespace omic
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL,
           RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL,
           RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL,
           RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO,
           RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO,
           RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO,
           RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_3_RX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_3_RX_BIT_REGS_STAT1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_3_RX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_3_RX_BIT_REGS_STAT1_PL;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_3_RX_BIT_REGS_STAT1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_3_RX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_BIT_REGS_STAT1_PL));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_3_RX_BIT_REGS_STAT1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.setBit<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.clearBit<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL));
#endif
    return i_data.getBit<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS,
           RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IORESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IORESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IORESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK,
           RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK,
           RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK,
           RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR,
           RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR,
           RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR,
           RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTLX5_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTLX5_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTLX5_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTLX5_PL;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTLX5_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTLX5_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTLX5_PL));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTLX5_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE,
           RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE,
           RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE,
           RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE,
           RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE,
           RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE,
           RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_STAT3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_4_RX_BIT_REGS_STAT3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_STAT3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_4_RX_BIT_REGS_STAT3_PL;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_4_RX_BIT_REGS_STAT3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_4_RX_BIT_REGS_STAT3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_BIT_REGS_STAT3_PL));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_4_RX_BIT_REGS_STAT3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001,
           RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001,
           RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001,
           RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011,
           RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011,
           RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011,
           RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101,
           RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101,
           RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101,
           RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110,
           RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110,
           RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110,
           RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ,
           RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ,
           RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ,
           RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_DATA,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_DATA,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_DATA,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_EDGE,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_EDGE,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_EDGE,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_BIST_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_BIST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_BIST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_BIST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_BIST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_BIST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_BIST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.setBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_BIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_BIST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_BIST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.clearBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_BIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_BIST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_BIST_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_BIST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_BIST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_BIST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL));
#endif
    return i_data.getBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_BIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_BIST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_BIST_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_BIST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_BIST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_BIST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_BIST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_BIST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_BIST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.setBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_BIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_BIST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_BIST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.clearBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_BIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_BIST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_BIST_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_BIST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_BIST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_BIST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL));
#endif
    return i_data.getBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_BIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_BIST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_TXCTL_CTL_REGS_TX_CNTL1_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_TXCTL_CTL_REGS_TX_CNTL1_PG;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_CTL_REGS_TX_CNTL1_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_TXCTL_CTL_REGS_TX_CNTL1_PG));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_CTL_REGS_TX_CNTL1_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_TXCTL_CTL_REGS_TX_CNTL1_PG));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL,
           TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_TXCTL_CTL_REGS_TX_CNTL1_PG));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL,
           TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_TXCTL_CTL_REGS_TX_CNTL1_PG));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL,
           TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT5_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT5_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT5_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT5_PG;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT5_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT5_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT5_PG));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT5_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return o_data.setBit<TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return o_data.clearBit<TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return i_data.getBit<TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return o_data.setBit<TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return o_data.clearBit<TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return i_data.getBit<TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL;
#endif
    return fapi2::getScom(i_target, TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL));
#endif
    return fapi2::putScom(i_target, TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN,
           TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN,
           TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN,
           TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL,
           TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL,
           TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL,
           TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL;
#endif
    return fapi2::getScom(i_target, TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL));
#endif
    return fapi2::putScom(i_target, TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN,
           TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN,
           TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN,
           TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL;
#endif
    return fapi2::getScom(i_target, TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL));
#endif
    return fapi2::putScom(i_target, TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_EN,
           TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_EN,
           TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_EN,
           TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_SEL,
           TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_SEL,
           TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_SEL,
           TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL;
#endif
    return fapi2::getScom(i_target, TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL));
#endif
    return fapi2::putScom(i_target, TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN,
           TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN,
           TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN,
           TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL;
#endif
    return fapi2::getScom(i_target, TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL));
#endif
    return fapi2::putScom(i_target, TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_EN,
           TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_EN,
           TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_EN,
           TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_SEL,
           TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_SEL,
           TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_SEL,
           TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL;
#endif
    return fapi2::getScom(i_target, TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return fapi2::putScom(i_target, TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY,
           TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY,
           TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY,
           TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL,
           TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL,
           TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL,
           TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL;
#endif
    return fapi2::getScom(i_target, TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL));
#endif
    return fapi2::putScom(i_target, TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.setBit<TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.getBit<TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.setBit<TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.getBit<TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL;
#endif
    return fapi2::getScom(i_target, TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL));
#endif
    return fapi2::putScom(i_target, TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL;
#endif
    return fapi2::getScom(i_target, TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL));
#endif
    return fapi2::putScom(i_target, TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN,
           TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN,
           TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN,
           TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL;
#endif
    return fapi2::getScom(i_target, TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL));
#endif
    return fapi2::putScom(i_target, TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN,
           TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN,
           TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN,
           TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL;
#endif
    return fapi2::getScom(i_target, TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL));
#endif
    return fapi2::putScom(i_target, TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_EN,
           TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_EN,
           TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_EN,
           TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_SEL,
           TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_SEL,
           TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_SEL,
           TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL;
#endif
    return fapi2::getScom(i_target, TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL));
#endif
    return fapi2::putScom(i_target, TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_EN,
           TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_EN,
           TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_EN,
           TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_SEL,
           TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_SEL,
           TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_SEL,
           TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL;
#endif
    return fapi2::getScom(i_target, TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return fapi2::putScom(i_target, TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_PDWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_PDWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_PDWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_INVERT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_INVERT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_INVERT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE,
           TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE,
           TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE,
           TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL;
#endif
    return fapi2::getScom(i_target, TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL));
#endif
    return fapi2::putScom(i_target, TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_EN,
           TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_EN,
           TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_EN,
           TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_SEL,
           TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_SEL,
           TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_SEL,
           TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL;
#endif
    return fapi2::getScom(i_target, TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL));
#endif
    return fapi2::putScom(i_target, TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_EN,
           TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_EN,
           TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_EN,
           TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_SEL,
           TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL));
#endif
    return o_data.insertFromRight<TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_SEL,
           TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL));
#endif
    return i_data.extractToRight<TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_SEL,
           TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL;
#endif
    return fapi2::getScom(i_target, TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL));
#endif
    return fapi2::putScom(i_target, TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_EN,
           TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_EN,
           TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_EN,
           TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_SEL,
           TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_SEL,
           TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_SEL,
           TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_1_DD_0_TX_BIT_REGS_MODE3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_1_DD_0_TX_BIT_REGS_MODE3_PL;
#endif
    return fapi2::getScom(i_target, TX0_1_DD_0_TX_BIT_REGS_MODE3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return fapi2::putScom(i_target, TX0_1_DD_0_TX_BIT_REGS_MODE3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_CTRL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_CTRL,
           TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_CTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_CTRL,
           TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_CTRL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_CTRL,
           TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL,
           TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL,
           TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL,
           TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.setBit<TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.clearBit<TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.getBit<TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.setBit<TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.clearBit<TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.getBit<TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.setBit<TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.clearBit<TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_0_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.getBit<TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_1_DD_TX_BIT_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_1_DD_TX_BIT_REGS_CNTL14_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_1_DD_TX_BIT_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_1_DD_TX_BIT_REGS_CNTL14_PL;
#endif
    return fapi2::getScom(i_target, TX0_1_DD_TX_BIT_REGS_CNTL14_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_1_DD_TX_BIT_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_1_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return fapi2::putScom(i_target, TX0_1_DD_TX_BIT_REGS_CNTL14_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS,
           TX0_1_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS,
           TX0_1_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_1_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<TX0_1_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS,
           TX0_1_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL,
           TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL,
           TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL,
           TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.setBit<TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.clearBit<TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.getBit<TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_1_DD_TX_BIT_REGS_CNTL24_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_1_DD_TX_BIT_REGS_CNTL24_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_1_DD_TX_BIT_REGS_CNTL24_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_1_DD_TX_BIT_REGS_CNTL24_PL;
#endif
    return fapi2::getScom(i_target, TX0_1_DD_TX_BIT_REGS_CNTL24_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_1_DD_TX_BIT_REGS_CNTL24_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_1_DD_TX_BIT_REGS_CNTL24_PL));
#endif
    return fapi2::putScom(i_target, TX0_1_DD_TX_BIT_REGS_CNTL24_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_TX_BIT_REGS_CNTL24_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN,
           TX0_1_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_TX_BIT_REGS_CNTL24_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN,
           TX0_1_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_1_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_TX_BIT_REGS_CNTL24_PL));
#endif
    return i_data.extractToRight<TX0_1_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN,
           TX0_1_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_1_DD_TX_BIT_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_1_DD_TX_BIT_REGS_CNTL8_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_1_DD_TX_BIT_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_1_DD_TX_BIT_REGS_CNTL8_PL;
#endif
    return fapi2::getScom(i_target, TX0_1_DD_TX_BIT_REGS_CNTL8_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_1_DD_TX_BIT_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_1_DD_TX_BIT_REGS_CNTL8_PL));
#endif
    return fapi2::putScom(i_target, TX0_1_DD_TX_BIT_REGS_CNTL8_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_TX_BIT_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN,
           TX0_1_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_TX_BIT_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN,
           TX0_1_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_1_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_TX_BIT_REGS_CNTL8_PL));
#endif
    return i_data.extractToRight<TX0_1_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN,
           TX0_1_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL;
#endif
    return fapi2::getScom(i_target, TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL));
#endif
    return fapi2::putScom(i_target, TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_EN,
           TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_EN,
           TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL));
#endif
    return i_data.extractToRight<TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_EN,
           TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_SEL,
           TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_SEL,
           TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL));
#endif
    return i_data.extractToRight<TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_SEL,
           TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL;
#endif
    return fapi2::getScom(i_target, TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL));
#endif
    return fapi2::putScom(i_target, TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_EN,
           TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_EN,
           TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL));
#endif
    return i_data.extractToRight<TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_EN,
           TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_SEL,
           TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_SEL,
           TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL));
#endif
    return i_data.extractToRight<TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_SEL,
           TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL;
#endif
    return fapi2::getScom(i_target, TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL));
#endif
    return fapi2::putScom(i_target, TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN,
           TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN,
           TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL));
#endif
    return i_data.extractToRight<TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN,
           TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}


}
}

#endif
