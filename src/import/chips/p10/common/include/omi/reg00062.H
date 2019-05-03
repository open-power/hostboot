/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omi/reg00062.H $          */
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

#ifndef __OMI_REG00062_H_
#define __OMI_REG00062_H_

namespace scomt
{
namespace omi
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W,
           2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W,
           2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W,
           2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101,
           2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101,
           2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101,
           2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111,
           2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111,
           2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111,
           2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001,
           2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001,
           2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001,
           2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010,
           2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010,
           2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010,
           2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL,
           2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL,
           2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL,
           2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL,
           2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL,
           2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL,
           2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL,
           2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL,
           2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL,
           2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO,
           2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO,
           2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO,
           2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_4_RX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_4_RX_BIT_REGS_STAT1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_4_RX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_4_RX_BIT_REGS_STAT1_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_4_RX_BIT_REGS_STAT1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_4_RX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_BIT_REGS_STAT1_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_4_RX_BIT_REGS_STAT1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010,
           2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010,
           2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010,
           2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100,
           2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100,
           2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100,
           2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110,
           2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA,
           2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA,
           2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA,
           2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE,
           2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE,
           2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE,
           2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXCTL_CTL_REGS_TX_CNTL8_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXCTL_CTL_REGS_TX_CNTL8_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXCTL_CTL_REGS_TX_CNTL8_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXCTL_CTL_REGS_TX_CNTL8_PG;
#endif
    return fapi2::getScom(i_target, TXCTL_CTL_REGS_TX_CNTL8_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXCTL_CTL_REGS_TX_CNTL8_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_CNTL8_PG));
#endif
    return fapi2::putScom(i_target, TXCTL_CTL_REGS_TX_CNTL8_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_CNTL8_PG));
#endif
    return o_data.insertFromRight<TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31,
           TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_CNTL8_PG));
#endif
    return o_data.insertFromRight<TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31,
           TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_CTL_REGS_TX_CNTL8_PG));
#endif
    return i_data.extractToRight<TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31,
           TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG;
#endif
    return fapi2::getScom(i_target, TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG));
#endif
    return fapi2::putScom(i_target, TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG));
#endif
    return o_data.insertFromRight<TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15,
           TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG));
#endif
    return o_data.insertFromRight<TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15,
           TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG));
#endif
    return i_data.extractToRight<TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15,
           TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG;
#endif
    return fapi2::getScom(i_target, TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return fapi2::putScom(i_target, TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return o_data.insertFromRight<TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return o_data.insertFromRight<TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return o_data.setBit<TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return o_data.clearBit<TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return i_data.extractToRight<TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return i_data.getBit<TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return o_data.insertFromRight<TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return o_data.insertFromRight<TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return o_data.setBit<TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return o_data.clearBit<TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return i_data.extractToRight<TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return i_data.getBit<TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS,
           0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS,
           0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS,
           0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL,
           0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL,
           0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL,
           0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN,
           0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN,
           0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN,
           0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_1_TX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_1_TX_BIT_REGS_STAT1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_1_TX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_1_TX_BIT_REGS_STAT1_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_1_TX_BIT_REGS_STAT1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_1_TX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_1_TX_BIT_REGS_STAT1_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_1_TX_BIT_REGS_STAT1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_1_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_1_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_1_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS,
           0_DEFAULT_DD_1_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_1_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_1_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_1_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_1_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS,
           0_DEFAULT_DD_1_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_1_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_1_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_1_TX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_1_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS,
           0_DEFAULT_DD_1_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_1_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_EN,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_EN,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_EN,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_SEL,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_SEL,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_SEL,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL_EN,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL_EN,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL_EN,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL_SEL,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL_SEL,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL_SEL,
           0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_CNTL5_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_D2_CTRL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_D2_CTRL,
           0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_D2_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_D2_CTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_D2_CTRL,
           0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_D2_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_D2_CTRL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_D2_CTRL,
           0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_D2_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL,
           0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL,
           0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL,
           0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_2_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_EN,
           0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_EN,
           0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_EN,
           0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_SEL,
           0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_SEL,
           0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_SEL,
           0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_EN,
           0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_EN,
           0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_EN,
           0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_SEL,
           0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_SEL,
           0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_SEL,
           0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL8_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL8_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL8_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL8_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL8_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN,
           0_DEFAULT_DD_3_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_3_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN,
           0_DEFAULT_DD_3_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_3_TX_BIT_REGS_CNTL8_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_3_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN,
           0_DEFAULT_DD_3_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_3_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL_EN,
           0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL_EN,
           0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL_EN,
           0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL_SEL,
           0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL_SEL,
           0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL_SEL,
           0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_4_TX_BIT_REGS_CNTL6_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.setBit<0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.getBit<0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL;
#endif
    return fapi2::getScom(i_target, 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL));
#endif
    return fapi2::putScom(i_target, 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL));
#endif
    return o_data.insertFromRight<0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL));
#endif
    return i_data.extractToRight<0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL;
#endif
    return fapi2::getScom(i_target, 1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return fapi2::putScom(i_target, 1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return o_data.insertFromRight<1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ,
           1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return o_data.insertFromRight<1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ,
           1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return i_data.extractToRight<1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ,
           1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_1_DD_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 1_DD_TX_BIT_REGS_CNTL15_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_1_DD_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 1_DD_TX_BIT_REGS_CNTL15_PL;
#endif
    return fapi2::getScom(i_target, 1_DD_TX_BIT_REGS_CNTL15_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_1_DD_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return fapi2::putScom(i_target, 1_DD_TX_BIT_REGS_CNTL15_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.setBit<1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.getBit<1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<1_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<1_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.setBit<1_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_1_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<1_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_1_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<1_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_1_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.getBit<1_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_1_DD_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 1_DD_TX_BIT_REGS_CNTL25_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_1_DD_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 1_DD_TX_BIT_REGS_CNTL25_PL;
#endif
    return fapi2::getScom(i_target, 1_DD_TX_BIT_REGS_CNTL25_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_1_DD_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL25_PL));
#endif
    return fapi2::putScom(i_target, 1_DD_TX_BIT_REGS_CNTL25_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_1_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL25_PL));
#endif
    return o_data.insertFromRight<1_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           1_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL25_PL));
#endif
    return o_data.insertFromRight<1_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           1_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_1_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL25_PL));
#endif
    return i_data.extractToRight<1_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           1_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_1_DD_TX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 1_DD_TX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_1_DD_TX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 1_DD_TX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::getScom(i_target, 1_DD_TX_BIT_REGS_CNTL6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_1_DD_TX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL6_PL));
#endif
    return fapi2::putScom(i_target, 1_DD_TX_BIT_REGS_CNTL6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_1_DD_TX_BIT_REGS_CNTL6_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<1_DD_TX_BIT_REGS_CNTL6_PL_EN,
           1_DD_TX_BIT_REGS_CNTL6_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_TX_BIT_REGS_CNTL6_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_TX_BIT_REGS_CNTL6_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<1_DD_TX_BIT_REGS_CNTL6_PL_EN,
           1_DD_TX_BIT_REGS_CNTL6_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_TX_BIT_REGS_CNTL6_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_1_DD_TX_BIT_REGS_CNTL6_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<1_DD_TX_BIT_REGS_CNTL6_PL_EN,
           1_DD_TX_BIT_REGS_CNTL6_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_TX_BIT_REGS_CNTL6_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_TX_BIT_REGS_CNTL6_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<1_DD_TX_BIT_REGS_CNTL6_PL_SEL,
           1_DD_TX_BIT_REGS_CNTL6_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_TX_BIT_REGS_CNTL6_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_TX_BIT_REGS_CNTL6_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<1_DD_TX_BIT_REGS_CNTL6_PL_SEL,
           1_DD_TX_BIT_REGS_CNTL6_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_TX_BIT_REGS_CNTL6_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_1_DD_TX_BIT_REGS_CNTL6_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_TX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<1_DD_TX_BIT_REGS_CNTL6_PL_SEL,
           1_DD_TX_BIT_REGS_CNTL6_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_TX_BIT_REGS_CNTL6_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_1_DD_2_TX_BIT_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 1_DD_2_TX_BIT_REGS_CNTL13_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_1_DD_2_TX_BIT_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 1_DD_2_TX_BIT_REGS_CNTL13_PL;
#endif
    return fapi2::getScom(i_target, 1_DD_2_TX_BIT_REGS_CNTL13_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_1_DD_2_TX_BIT_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(1_DD_2_TX_BIT_REGS_CNTL13_PL));
#endif
    return fapi2::putScom(i_target, 1_DD_2_TX_BIT_REGS_CNTL13_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_1_DD_2_TX_BIT_REGS_CNTL13_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_2_TX_BIT_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<1_DD_2_TX_BIT_REGS_CNTL13_PL_EN,
           1_DD_2_TX_BIT_REGS_CNTL13_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_2_TX_BIT_REGS_CNTL13_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_2_TX_BIT_REGS_CNTL13_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_2_TX_BIT_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<1_DD_2_TX_BIT_REGS_CNTL13_PL_EN,
           1_DD_2_TX_BIT_REGS_CNTL13_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_2_TX_BIT_REGS_CNTL13_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_1_DD_2_TX_BIT_REGS_CNTL13_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_2_TX_BIT_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<1_DD_2_TX_BIT_REGS_CNTL13_PL_EN,
           1_DD_2_TX_BIT_REGS_CNTL13_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_2_TX_BIT_REGS_CNTL13_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_2_TX_BIT_REGS_CNTL13_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_2_TX_BIT_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<1_DD_2_TX_BIT_REGS_CNTL13_PL_SEL,
           1_DD_2_TX_BIT_REGS_CNTL13_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_2_TX_BIT_REGS_CNTL13_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_2_TX_BIT_REGS_CNTL13_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_2_TX_BIT_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<1_DD_2_TX_BIT_REGS_CNTL13_PL_SEL,
           1_DD_2_TX_BIT_REGS_CNTL13_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_2_TX_BIT_REGS_CNTL13_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_1_DD_2_TX_BIT_REGS_CNTL13_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_2_TX_BIT_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<1_DD_2_TX_BIT_REGS_CNTL13_PL_SEL,
           1_DD_2_TX_BIT_REGS_CNTL13_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_2_TX_BIT_REGS_CNTL13_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_1_DD_2_TX_BIT_REGS_CNTL23_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 1_DD_2_TX_BIT_REGS_CNTL23_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_1_DD_2_TX_BIT_REGS_CNTL23_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 1_DD_2_TX_BIT_REGS_CNTL23_PL;
#endif
    return fapi2::getScom(i_target, 1_DD_2_TX_BIT_REGS_CNTL23_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_1_DD_2_TX_BIT_REGS_CNTL23_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(1_DD_2_TX_BIT_REGS_CNTL23_PL));
#endif
    return fapi2::putScom(i_target, 1_DD_2_TX_BIT_REGS_CNTL23_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_1_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_2_TX_BIT_REGS_CNTL23_PL));
#endif
    return o_data.insertFromRight<1_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN,
           1_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_2_TX_BIT_REGS_CNTL23_PL));
#endif
    return o_data.insertFromRight<1_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN,
           1_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_1_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_2_TX_BIT_REGS_CNTL23_PL));
#endif
    return i_data.extractToRight<1_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN,
           1_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_1_DD_2_TX_BIT_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 1_DD_2_TX_BIT_REGS_CNTL2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_1_DD_2_TX_BIT_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 1_DD_2_TX_BIT_REGS_CNTL2_PL;
#endif
    return fapi2::getScom(i_target, 1_DD_2_TX_BIT_REGS_CNTL2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_1_DD_2_TX_BIT_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(1_DD_2_TX_BIT_REGS_CNTL2_PL));
#endif
    return fapi2::putScom(i_target, 1_DD_2_TX_BIT_REGS_CNTL2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_1_DD_2_TX_BIT_REGS_CNTL2_PL_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_2_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<1_DD_2_TX_BIT_REGS_CNTL2_PL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_2_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_2_TX_BIT_REGS_CNTL2_PL_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_2_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<1_DD_2_TX_BIT_REGS_CNTL2_PL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_2_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_2_TX_BIT_REGS_CNTL2_PL_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_2_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<1_DD_2_TX_BIT_REGS_CNTL2_PL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_2_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_1_DD_2_TX_BIT_REGS_CNTL2_PL_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_2_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<1_DD_2_TX_BIT_REGS_CNTL2_PL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_2_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_1_DD_2_TX_BIT_REGS_CNTL2_PL_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_2_TX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<1_DD_2_TX_BIT_REGS_CNTL2_PL_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_2_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_1_DD_2_TX_BIT_REGS_CNTL2_PL_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_2_TX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<1_DD_2_TX_BIT_REGS_CNTL2_PL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_2_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_2_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_2_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<1_DD_2_TX_BIT_REGS_CNTL2_PL_DOM_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_2_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_2_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_2_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<1_DD_2_TX_BIT_REGS_CNTL2_PL_DOM_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_2_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_2_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_2_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<1_DD_2_TX_BIT_REGS_CNTL2_PL_DOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_2_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_1_DD_2_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_2_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<1_DD_2_TX_BIT_REGS_CNTL2_PL_DOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_2_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_1_DD_2_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_2_TX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<1_DD_2_TX_BIT_REGS_CNTL2_PL_DOM_IORESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_2_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_1_DD_2_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_2_TX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<1_DD_2_TX_BIT_REGS_CNTL2_PL_DOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_2_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_1_DD_3_TX_BIT_REGS_CNTL19_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 1_DD_3_TX_BIT_REGS_CNTL19_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_1_DD_3_TX_BIT_REGS_CNTL19_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 1_DD_3_TX_BIT_REGS_CNTL19_PL;
#endif
    return fapi2::getScom(i_target, 1_DD_3_TX_BIT_REGS_CNTL19_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_1_DD_3_TX_BIT_REGS_CNTL19_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(1_DD_3_TX_BIT_REGS_CNTL19_PL));
#endif
    return fapi2::putScom(i_target, 1_DD_3_TX_BIT_REGS_CNTL19_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_1_DD_3_TX_BIT_REGS_CNTL19_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_3_TX_BIT_REGS_CNTL19_PL));
#endif
    return o_data.insertFromRight<1_DD_3_TX_BIT_REGS_CNTL19_PL_EN,
           1_DD_3_TX_BIT_REGS_CNTL19_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_3_TX_BIT_REGS_CNTL19_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_3_TX_BIT_REGS_CNTL19_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_3_TX_BIT_REGS_CNTL19_PL));
#endif
    return o_data.insertFromRight<1_DD_3_TX_BIT_REGS_CNTL19_PL_EN,
           1_DD_3_TX_BIT_REGS_CNTL19_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_3_TX_BIT_REGS_CNTL19_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_1_DD_3_TX_BIT_REGS_CNTL19_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_3_TX_BIT_REGS_CNTL19_PL));
#endif
    return i_data.extractToRight<1_DD_3_TX_BIT_REGS_CNTL19_PL_EN,
           1_DD_3_TX_BIT_REGS_CNTL19_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_3_TX_BIT_REGS_CNTL19_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_3_TX_BIT_REGS_CNTL19_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_3_TX_BIT_REGS_CNTL19_PL));
#endif
    return o_data.insertFromRight<1_DD_3_TX_BIT_REGS_CNTL19_PL_SEL,
           1_DD_3_TX_BIT_REGS_CNTL19_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_3_TX_BIT_REGS_CNTL19_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_3_TX_BIT_REGS_CNTL19_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_3_TX_BIT_REGS_CNTL19_PL));
#endif
    return o_data.insertFromRight<1_DD_3_TX_BIT_REGS_CNTL19_PL_SEL,
           1_DD_3_TX_BIT_REGS_CNTL19_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_3_TX_BIT_REGS_CNTL19_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_1_DD_3_TX_BIT_REGS_CNTL19_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_3_TX_BIT_REGS_CNTL19_PL));
#endif
    return i_data.extractToRight<1_DD_3_TX_BIT_REGS_CNTL19_PL_SEL,
           1_DD_3_TX_BIT_REGS_CNTL19_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_3_TX_BIT_REGS_CNTL19_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_1_DD_3_TX_BIT_REGS_CNTL29_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 1_DD_3_TX_BIT_REGS_CNTL29_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_1_DD_3_TX_BIT_REGS_CNTL29_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 1_DD_3_TX_BIT_REGS_CNTL29_PL;
#endif
    return fapi2::getScom(i_target, 1_DD_3_TX_BIT_REGS_CNTL29_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_1_DD_3_TX_BIT_REGS_CNTL29_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(1_DD_3_TX_BIT_REGS_CNTL29_PL));
#endif
    return fapi2::putScom(i_target, 1_DD_3_TX_BIT_REGS_CNTL29_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_1_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_3_TX_BIT_REGS_CNTL29_PL));
#endif
    return o_data.insertFromRight<1_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN,
           1_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_1_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_3_TX_BIT_REGS_CNTL29_PL));
#endif
    return o_data.insertFromRight<1_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN,
           1_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_1_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(1_DD_3_TX_BIT_REGS_CNTL29_PL));
#endif
    return i_data.extractToRight<1_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN,
           1_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 1_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.setBit<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.getBit<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.setBit<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.getBit<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_DOM_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_DOM_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_DOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_DOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_DOM_IORESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_DOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_1_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN,
           2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN,
           2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN,
           2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL,
           2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL,
           2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL,
           2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN,
           2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN,
           2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN,
           2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL_EN,
           2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL_EN,
           2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL_EN,
           2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL_SEL,
           2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL_SEL,
           2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL_SEL,
           2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_TX_BIT_REGS_CNTL6_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_EN,
           2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_EN,
           2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_EN,
           2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_SEL,
           2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_SEL,
           2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_SEL,
           2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN,
           2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN,
           2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN,
           2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS,
           2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS,
           2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS,
           2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL,
           2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL,
           2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL,
           2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.setBit<2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.clearBit<2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.getBit<2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL;
#endif
    return fapi2::getScom(i_target, 2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL));
#endif
    return fapi2::putScom(i_target, 2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN,
           2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL));
#endif
    return o_data.insertFromRight<2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN,
           2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL));
#endif
    return i_data.extractToRight<2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN,
           2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access 2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
