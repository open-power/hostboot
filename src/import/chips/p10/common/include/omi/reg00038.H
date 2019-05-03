/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omi/reg00038.H $          */
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

#ifndef __OMI_REG00038_H_
#define __OMI_REG00038_H_

namespace scomt
{
namespace omi
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIME_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIME_VAL,
           2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIME_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIME_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIME_VAL,
           2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIME_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIME_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIME_VAL,
           2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIME_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.setBit<2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.clearBit<2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.getBit<2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_DISABLE_SM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_DISABLE_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_DISABLE_SM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_DISABLE_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_DISABLE_SM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.setBit<2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_DISABLE_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.clearBit<2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_DISABLE_SM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_DISABLE_SM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_DISABLE_SM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.getBit<2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001,
           2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001,
           2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001,
           2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011,
           2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011,
           2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011,
           2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101,
           2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101,
           2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101,
           2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110,
           2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110,
           2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110,
           2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL_DATA,
           2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL_DATA,
           2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL_DATA,
           2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL_EDGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL_EDGE,
           2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL_EDGE,
           2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL_EDGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL_EDGE,
           2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_DAC_REGS_CNTL16_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN,
           2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN,
           2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN,
           2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_FREQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_FREQ,
           2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_FREQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_FREQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_FREQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_FREQ,
           2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_FREQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_FREQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_FREQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_FREQ,
           2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_FREQ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_FREQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_3_RX_BIT_REGS_CNTLX5_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_3_RX_BIT_REGS_CNTLX5_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_3_RX_BIT_REGS_CNTLX5_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_3_RX_BIT_REGS_CNTLX5_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_3_RX_BIT_REGS_CNTLX5_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_3_RX_BIT_REGS_CNTLX5_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_BIT_REGS_CNTLX5_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_3_RX_BIT_REGS_CNTLX5_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010,
           2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010,
           2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010,
           2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100,
           2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100,
           2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100,
           2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_COARSE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_COARSE,
           2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_COARSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_COARSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_COARSE,
           2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_COARSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_COARSE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_COARSE,
           2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_COARSE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_COARSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_GAIN,
           2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_GAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_GAIN,
           2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_GAIN,
           2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_GAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH,
           2_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH,
           2_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH,
           2_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W,
           2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W,
           2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W,
           2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101,
           2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101,
           2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101,
           2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111,
           2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111,
           2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111,
           2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001,
           2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001,
           2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001,
           2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010,
           2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010,
           2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010,
           2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL,
           2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL,
           2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL,
           2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL,
           2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL,
           2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL,
           2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT,
           2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT,
           2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT,
           2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_PHASE_STEP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_PHASE_STEP,
           2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_PHASE_STEP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_PHASE_STEP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_PHASE_STEP,
           2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_PHASE_STEP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_PHASE_STEP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_PHASE_STEP,
           2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_PHASE_STEP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_5_RX_BIT_REGS_STAT2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_BIT_REGS_STAT2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_5_RX_BIT_REGS_STAT2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_BIT_REGS_STAT2_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_5_RX_BIT_REGS_STAT2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_5_RX_BIT_REGS_STAT2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_BIT_REGS_STAT2_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_5_RX_BIT_REGS_STAT2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXCTL_CTL_REGS_TX_CNTL7_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXCTL_CTL_REGS_TX_CNTL7_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXCTL_CTL_REGS_TX_CNTL7_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXCTL_CTL_REGS_TX_CNTL7_PG;
#endif
    return fapi2::getScom(i_target, TXCTL_CTL_REGS_TX_CNTL7_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXCTL_CTL_REGS_TX_CNTL7_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_CNTL7_PG));
#endif
    return fapi2::putScom(i_target, TXCTL_CTL_REGS_TX_CNTL7_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_CNTL7_PG));
#endif
    return o_data.insertFromRight<TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15,
           TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_CNTL7_PG));
#endif
    return o_data.insertFromRight<TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15,
           TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_CNTL7_PG));
#endif
    return i_data.extractToRight<TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15,
           TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXCTL_CTL_REGS_TX_MODE1_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXCTL_CTL_REGS_TX_MODE1_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXCTL_CTL_REGS_TX_MODE1_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXCTL_CTL_REGS_TX_MODE1_PG;
#endif
    return fapi2::getScom(i_target, TXCTL_CTL_REGS_TX_MODE1_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXCTL_CTL_REGS_TX_MODE1_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return fapi2::putScom(i_target, TXCTL_CTL_REGS_TX_MODE1_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN,
           TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN,
           TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN,
           TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<TXCTL_CTL_REGS_TX_MODE1_PG_16TO1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<TXCTL_CTL_REGS_TX_MODE1_PG_16TO1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<TXCTL_CTL_REGS_TX_MODE1_PG_16TO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<TXCTL_CTL_REGS_TX_MODE1_PG_16TO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<TXCTL_CTL_REGS_TX_MODE1_PG_16TO1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<TXCTL_CTL_REGS_TX_MODE1_PG_16TO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG;
#endif
    return fapi2::getScom(i_target, TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG));
#endif
    return fapi2::putScom(i_target, TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG));
#endif
    return o_data.insertFromRight<TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23,
           TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG));
#endif
    return o_data.insertFromRight<TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23,
           TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG));
#endif
    return i_data.extractToRight<TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23,
           TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN,
           0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN,
           0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN,
           0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_1_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL1G_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_1_TX_BIT_REGS_CNTL1G_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL1G_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_1_TX_BIT_REGS_CNTL1G_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_1_TX_BIT_REGS_CNTL1G_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL1G_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_1_TX_BIT_REGS_CNTL1G_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_1_TX_BIT_REGS_CNTL1G_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN,
           0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN,
           0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN,
           0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL,
           0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL,
           0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL,
           0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_1_TX_BIT_REGS_CNTL21_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK,
           0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK,
           0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK,
           0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_EN,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_EN,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_EN,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_SEL,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_SEL,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_SEL,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL27_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_EN,
           0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_EN,
           0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_EN,
           0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_SEL,
           0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_SEL,
           0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_SEL,
           0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL7_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ,
           0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ,
           0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ,
           0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE,
           0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE,
           0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE,
           0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN,
           0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN,
           0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN,
           0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL,
           0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL,
           0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL,
           0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL20_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN,
           0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN,
           0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN,
           0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_EN,
           0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_EN,
           0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_EN,
           0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_SEL,
           0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_SEL,
           0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_SEL,
           0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL4_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY,
           0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY,
           0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY,
           0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL,
           0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL,
           0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL,
           0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_1_DD_0_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 1_DD_0_TX_BIT_REGS_CNTL10_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_1_DD_0_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 1_DD_0_TX_BIT_REGS_CNTL10_PL;
#endif
    return fapi2::getScom(i_target, 1_DD_0_TX_BIT_REGS_CNTL10_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_1_DD_0_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(1_DD_0_TX_BIT_REGS_CNTL10_PL));
#endif
    return fapi2::putScom(i_target, 1_DD_0_TX_BIT_REGS_CNTL10_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_1_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_0_TX_BIT_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<1_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           1_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_0_TX_BIT_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<1_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           1_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_1_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_0_TX_BIT_REGS_CNTL10_PL));
#endif
    return i_data.extractToRight<1_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           1_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_1_DD_0_TX_BIT_REGS_CNTL20_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 1_DD_0_TX_BIT_REGS_CNTL20_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_1_DD_0_TX_BIT_REGS_CNTL20_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 1_DD_0_TX_BIT_REGS_CNTL20_PL;
#endif
    return fapi2::getScom(i_target, 1_DD_0_TX_BIT_REGS_CNTL20_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_1_DD_0_TX_BIT_REGS_CNTL20_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(1_DD_0_TX_BIT_REGS_CNTL20_PL));
#endif
    return fapi2::putScom(i_target, 1_DD_0_TX_BIT_REGS_CNTL20_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_1_DD_0_TX_BIT_REGS_CNTL20_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_0_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<1_DD_0_TX_BIT_REGS_CNTL20_PL_EN,
           1_DD_0_TX_BIT_REGS_CNTL20_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_0_TX_BIT_REGS_CNTL20_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_0_TX_BIT_REGS_CNTL20_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_0_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<1_DD_0_TX_BIT_REGS_CNTL20_PL_EN,
           1_DD_0_TX_BIT_REGS_CNTL20_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_0_TX_BIT_REGS_CNTL20_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_1_DD_0_TX_BIT_REGS_CNTL20_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_0_TX_BIT_REGS_CNTL20_PL));
#endif
    return i_data.extractToRight<1_DD_0_TX_BIT_REGS_CNTL20_PL_EN,
           1_DD_0_TX_BIT_REGS_CNTL20_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_0_TX_BIT_REGS_CNTL20_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_0_TX_BIT_REGS_CNTL20_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_0_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<1_DD_0_TX_BIT_REGS_CNTL20_PL_SEL,
           1_DD_0_TX_BIT_REGS_CNTL20_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_0_TX_BIT_REGS_CNTL20_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_0_TX_BIT_REGS_CNTL20_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_0_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<1_DD_0_TX_BIT_REGS_CNTL20_PL_SEL,
           1_DD_0_TX_BIT_REGS_CNTL20_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_0_TX_BIT_REGS_CNTL20_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_1_DD_0_TX_BIT_REGS_CNTL20_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_0_TX_BIT_REGS_CNTL20_PL));
#endif
    return i_data.extractToRight<1_DD_0_TX_BIT_REGS_CNTL20_PL_SEL,
           1_DD_0_TX_BIT_REGS_CNTL20_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_0_TX_BIT_REGS_CNTL20_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
