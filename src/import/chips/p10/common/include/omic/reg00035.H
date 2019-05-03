/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omic/reg00035.H $         */
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

#ifndef __OMIC_REG00035_H_
#define __OMIC_REG00035_H_

namespace scomt
{
namespace omic
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL;
#endif
    return fapi2::getScom(i_target, TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL));
#endif
    return fapi2::putScom(i_target, TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.setBit<TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.clearBit<TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL));
#endif
    return i_data.extractToRight<TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL));
#endif
    return i_data.getBit<TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_3_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_1_DD_3_TX_BIT_REGS_CNTL9_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_1_DD_3_TX_BIT_REGS_CNTL9_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_1_DD_3_TX_BIT_REGS_CNTL9_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_1_DD_3_TX_BIT_REGS_CNTL9_PL;
#endif
    return fapi2::getScom(i_target, TX0_1_DD_3_TX_BIT_REGS_CNTL9_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_1_DD_3_TX_BIT_REGS_CNTL9_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_1_DD_3_TX_BIT_REGS_CNTL9_PL));
#endif
    return fapi2::putScom(i_target, TX0_1_DD_3_TX_BIT_REGS_CNTL9_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_3_TX_BIT_REGS_CNTL9_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN,
           TX0_1_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_1_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_3_TX_BIT_REGS_CNTL9_PL));
#endif
    return o_data.insertFromRight<TX0_1_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN,
           TX0_1_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_1_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_1_DD_3_TX_BIT_REGS_CNTL9_PL));
#endif
    return i_data.extractToRight<TX0_1_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN,
           TX0_1_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_1_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL10_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL10_PL;
#endif
    return fapi2::getScom(i_target, TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL10_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL10_PL));
#endif
    return fapi2::putScom(i_target, TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL10_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL10_PL));
#endif
    return i_data.extractToRight<TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL;
#endif
    return fapi2::getScom(i_target, TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL));
#endif
    return fapi2::putScom(i_target, TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL_EN,
           TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL_EN,
           TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL));
#endif
    return i_data.extractToRight<TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL_EN,
           TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL_SEL,
           TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL_SEL,
           TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL));
#endif
    return i_data.extractToRight<TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL_SEL,
           TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL20_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL;
#endif
    return fapi2::getScom(i_target, TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL));
#endif
    return fapi2::putScom(i_target, TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.setBit<TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.clearBit<TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL));
#endif
    return i_data.extractToRight<TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL));
#endif
    return i_data.getBit<TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::getScom(i_target, TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL));
#endif
    return fapi2::putScom(i_target, TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL_EN,
           TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL_EN,
           TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL_EN,
           TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL_SEL,
           TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL_SEL,
           TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL_SEL,
           TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL6_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL;
#endif
    return fapi2::getScom(i_target, TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL));
#endif
    return fapi2::putScom(i_target, TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE,
           TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE,
           TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE,
           TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE,
           TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE,
           TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE,
           TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL;
#endif
    return fapi2::getScom(i_target, TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL));
#endif
    return fapi2::putScom(i_target, TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN,
           TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN,
           TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL));
#endif
    return i_data.extractToRight<TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN,
           TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL;
#endif
    return fapi2::getScom(i_target, TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return fapi2::putScom(i_target, TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL;
#endif
    return fapi2::getScom(i_target, TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL));
#endif
    return fapi2::putScom(i_target, TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN,
           TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN,
           TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL));
#endif
    return i_data.extractToRight<TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN,
           TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL1G_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL1G_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL1G_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL1G_PL;
#endif
    return fapi2::getScom(i_target, TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL1G_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL1G_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL1G_PL));
#endif
    return fapi2::putScom(i_target, TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL1G_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL;
#endif
    return fapi2::getScom(i_target, TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL));
#endif
    return fapi2::putScom(i_target, TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_EN,
           TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_EN,
           TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL));
#endif
    return i_data.extractToRight<TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_EN,
           TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_SEL,
           TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_SEL,
           TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL));
#endif
    return i_data.extractToRight<TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_SEL,
           TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL21_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_2_DEFAULT_DD_5_TX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_2_DEFAULT_DD_5_TX_BIT_REGS_STAT1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_2_DEFAULT_DD_5_TX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX0_2_DEFAULT_DD_5_TX_BIT_REGS_STAT1_PL;
#endif
    return fapi2::getScom(i_target, TX0_2_DEFAULT_DD_5_TX_BIT_REGS_STAT1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_2_DEFAULT_DD_5_TX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return fapi2::putScom(i_target, TX0_2_DEFAULT_DD_5_TX_BIT_REGS_STAT1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_5_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_5_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS,
           TX0_2_DEFAULT_DD_5_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_5_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_2_DEFAULT_DD_5_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<TX0_2_DEFAULT_DD_5_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS,
           TX0_2_DEFAULT_DD_5_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_5_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_2_DEFAULT_DD_5_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX0_2_DEFAULT_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<TX0_2_DEFAULT_DD_5_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS,
           TX0_2_DEFAULT_DD_5_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_2_DEFAULT_DD_5_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}


}
}

#endif
