/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omi/reg00019.H $          */
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

#ifndef __OMI_REG00019_H_
#define __OMI_REG00019_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL,
           RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL,
           RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL,
           RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_2_RX_BIT_REGS_STAT6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_BIT_REGS_STAT6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_2_RX_BIT_REGS_STAT6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_BIT_REGS_STAT6_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_2_RX_BIT_REGS_STAT6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_2_RX_BIT_REGS_STAT6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_BIT_REGS_STAT6_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_2_RX_BIT_REGS_STAT6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_GAIN,
           RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_GAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_GAIN,
           RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_GAIN,
           RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_GAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK1,
           RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK1,
           RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK1,
           RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK2,
           RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK2,
           RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK2,
           RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W,
           RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W,
           RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W,
           RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111,
           RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111,
           RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111,
           RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001,
           RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001,
           RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001,
           RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_DATA,
           RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_DATA,
           RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_DATA,
           RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_DATA,
           RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_DATA,
           RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_DATA,
           RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_EDGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_EDGE,
           RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_EDGE,
           RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_EDGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_EDGE,
           RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_EDGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_EDGE,
           RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_EDGE,
           RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_EDGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_EDGE,
           RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL1G_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL1G_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL1G_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL1G_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL1G_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL1G_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL1G_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL1G_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL,
           TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL,
           TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL,
           TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE,
           TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE,
           TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE,
           TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT,
           TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT,
           TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT,
           TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_EN,
           TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_EN,
           TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_EN,
           TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_SEL,
           TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_SEL,
           TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_SEL,
           TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_EN,
           TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_EN,
           TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_EN,
           TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_SEL,
           TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_SEL,
           TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_SEL,
           TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ,
           TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ,
           TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ,
           TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE,
           TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE,
           TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE,
           TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN,
           TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN,
           TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN,
           TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL,
           TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL,
           TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL,
           TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN,
           TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN,
           TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN,
           TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_EN,
           TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_EN,
           TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_EN,
           TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_SEL,
           TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_SEL,
           TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_SEL,
           TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY,
           TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY,
           TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY,
           TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL,
           TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL,
           TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL,
           TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE,
           TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE,
           TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE,
           TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE,
           TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE,
           TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE,
           TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_1_DD_3_TX_BIT_REGS_CNTL26_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_1_DD_3_TX_BIT_REGS_CNTL26_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_1_DD_3_TX_BIT_REGS_CNTL26_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_1_DD_3_TX_BIT_REGS_CNTL26_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_1_DD_3_TX_BIT_REGS_CNTL26_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_1_DD_3_TX_BIT_REGS_CNTL26_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_3_TX_BIT_REGS_CNTL26_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_1_DD_3_TX_BIT_REGS_CNTL26_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_3_TX_BIT_REGS_CNTL26_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN,
           TXPACKS_1_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_3_TX_BIT_REGS_CNTL26_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN,
           TXPACKS_1_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_1_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_3_TX_BIT_REGS_CNTL26_PL));
#endif
    return i_data.extractToRight<TXPACKS_1_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN,
           TXPACKS_1_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
