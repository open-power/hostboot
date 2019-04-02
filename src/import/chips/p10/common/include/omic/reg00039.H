/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omic/reg00039.H $         */
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

#ifndef __OMIC_REG00039_H_
#define __OMIC_REG00039_H_

namespace scomt
{
namespace omic
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8002b8680c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8002b8680c01083f;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x8002b8680c01083f));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8002b8680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8002b8680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8002b8680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8002c0680c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8002c0680c01083f;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x8002c0680c01083f));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8002c0680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8002c0680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8002c0680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8002c8680c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8002c8680c01083f;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x8002c8680c01083f));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8002c8680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8002c8680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8002c8680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8002d0680c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8002d0680c01083f;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x8002d0680c01083f));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8002d0680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8002d0680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8002d0680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800068680c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800068680c01083f;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800068680c01083f));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800068680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL_COARSE,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL_COARSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL_COARSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800068680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL_COARSE,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL_COARSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800068680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL_COARSE,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL_COARSE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL_COARSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL_GAIN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800068680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL_GAIN,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL_GAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800068680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL_GAIN,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL_GAIN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800068680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL_GAIN,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL_GAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL13_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800070680c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800070680c01083f;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800070680c01083f));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800070680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800070680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800070680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800070680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800070680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800070680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800078680c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800078680c01083f;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800078680c01083f));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800078680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800078680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800078680c01083f));
#endif
    return o_data.setBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800078680c01083f));
#endif
    return o_data.clearBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800078680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800078680c01083f));
#endif
    return i_data.getBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800078680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800078680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800078680c01083f));
#endif
    return o_data.setBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800078680c01083f));
#endif
    return o_data.clearBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800078680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800078680c01083f));
#endif
    return i_data.getBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800080680c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800080680c01083f;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800080680c01083f));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800080680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800080680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800080680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800080680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800080680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800080680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800088680c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800088680c01083f;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800088680c01083f));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800088680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL_DATA,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800088680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL_DATA,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800088680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL_DATA,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800088680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800088680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800088680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL17_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800090680c01083f;
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
    scomt::last_scom = 0x800090680c01083f;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800090680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800090680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800090680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800090680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800090680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800090680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800090680c01083f));
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
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800008680c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800008680c01083f;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800008680c01083f));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800008680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800008680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800008680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800008680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800008680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800008680c01083f));
#endif
    return o_data.setBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800008680c01083f));
#endif
    return o_data.clearBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800008680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800008680c01083f));
#endif
    return i_data.getBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800008680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800008680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800008680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800008680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800008680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800008680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800018680c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800018680c01083f;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800018680c01083f));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800018680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800018680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800018680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800018680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800018680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800018680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800020680c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800020680c01083f;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800020680c01083f));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800020680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_GAIN,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_GAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800020680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_GAIN,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800020680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_GAIN,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_GAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_FREQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800020680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_FREQ,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_FREQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_FREQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_FREQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800020680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_FREQ,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_FREQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_FREQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_FREQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800020680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_FREQ,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_FREQ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL4_PL_FREQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800030680c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800030680c01083f;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800030680c01083f));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800030680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800030680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800030680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800030680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800030680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800030680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800038680c01083f;
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
    scomt::last_scom = 0x800038680c01083f;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800038680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800038680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800038680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800038680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800038680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800038680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800038680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800038680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800038680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800038680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800038680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800038680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800038680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800038680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800038680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800038680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800038680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800038680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800038680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800038680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800038680c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800038680c01083f));
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
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800040680c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800040680c01083f;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800040680c01083f));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800040680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800040680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800040680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800040680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800040680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800040680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800048680c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800048680c01083f;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800048680c01083f));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800048680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800048680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800048680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800048680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800048680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800048680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL,
           RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800000680c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800000680c01083f;
#endif
    return fapi2::getScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return fapi2::putScom(i_target, RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.setBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.clearBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return i_data.getBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.setBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.clearBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return i_data.getBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.setBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.clearBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return i_data.getBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.setBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.clearBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return i_data.getBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.setBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.clearBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return i_data.getBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.setBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.clearBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return i_data.getBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.setBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.clearBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return i_data.getBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.insertFromRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.setBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return o_data.clearBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return i_data.extractToRight<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800000680c01083f));
#endif
    return i_data.getBit<RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_CTL_REGS_TX_CNTL10_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800c2c600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_CTL_REGS_TX_CNTL10_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800c2c600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_CTL_REGS_TX_CNTL10_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_CTL_REGS_TX_CNTL10_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800c2c600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_CTL_REGS_TX_CNTL10_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c2c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63,
           TX0_TXCTL_CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c2c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63,
           TX0_TXCTL_CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c2c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63,
           TX0_TXCTL_CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800c44600c01083f;
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
    scomt::last_scom = 0x800c44600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_CTL_REGS_TX_CNTL1_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800c44600c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800c44600c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800c44600c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800c44600c01083f));
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
static inline fapi2::ReturnCode PREP_TX0_TXCTL_CTL_REGS_TX_CNTL2_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800c4c600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_CTL_REGS_TX_CNTL2_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800c4c600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_CTL_REGS_TX_CNTL2_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_CTL_REGS_TX_CNTL2_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800c4c600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_CTL_REGS_TX_CNTL2_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_FINE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c4c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_FINE_SEL,
           TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_FINE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_FINE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_FINE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c4c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_FINE_SEL,
           TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_FINE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_FINE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_FINE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c4c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_FINE_SEL,
           TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_FINE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_FINE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c4c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL,
           TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c4c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL,
           TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c4c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL,
           TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_BER_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c4c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_BER_SEL,
           TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_BER_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_BER_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_BER_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c4c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_BER_SEL,
           TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_BER_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_BER_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_BER_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c4c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_BER_SEL,
           TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_BER_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_A_BER_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c4c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c4c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c4c600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c4c600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c4c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c4c600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c4c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c4c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c4c600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c4c600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c4c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c4c600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800c54600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800c54600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_CTL_REGS_TX_CNTL3_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800c54600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_CTL_REGS_TX_CNTL3_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_FINE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c54600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_FINE_SEL,
           TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_FINE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_FINE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_FINE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c54600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_FINE_SEL,
           TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_FINE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_FINE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_FINE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c54600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_FINE_SEL,
           TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_FINE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_FINE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_COARSE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c54600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_COARSE_SEL,
           TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_COARSE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_COARSE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_COARSE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c54600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_COARSE_SEL,
           TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_COARSE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_COARSE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_COARSE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c54600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_COARSE_SEL,
           TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_COARSE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_COARSE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_BER_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c54600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_BER_SEL,
           TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_BER_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_BER_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_BER_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c54600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_BER_SEL,
           TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_BER_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_BER_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_BER_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c54600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_BER_SEL,
           TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_BER_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_BER_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800c5c600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800c5c600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_CTL_REGS_TX_CNTL4_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800c5c600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_CTL_REGS_TX_CNTL4_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c5c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL,
           TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c5c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL,
           TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c5c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL,
           TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c5c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c5c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c5c600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c5c600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c5c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c5c600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_CTL_REGS_TX_CNTL5_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800c64600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_CTL_REGS_TX_CNTL5_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800c64600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_CTL_REGS_TX_CNTL5_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_CTL_REGS_TX_CNTL5_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800c64600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_CTL_REGS_TX_CNTL5_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c64600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET,
           TX0_TXCTL_CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c64600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET,
           TX0_TXCTL_CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c64600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET,
           TX0_TXCTL_CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_CTL_REGS_TX_CNTL6_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800c6c600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_CTL_REGS_TX_CNTL6_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800c6c600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_CTL_REGS_TX_CNTL6_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_CTL_REGS_TX_CNTL6_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800c6c600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_CTL_REGS_TX_CNTL6_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c6c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH,
           TX0_TXCTL_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c6c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH,
           TX0_TXCTL_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c6c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH,
           TX0_TXCTL_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800c74600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800c74600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_CTL_REGS_TX_CNTL7_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800c74600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_CTL_REGS_TX_CNTL7_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c74600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15,
           TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c74600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15,
           TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c74600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15,
           TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_CTL_REGS_TX_CNTL8_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800c7c600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_CTL_REGS_TX_CNTL8_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800c7c600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_CTL_REGS_TX_CNTL8_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_CTL_REGS_TX_CNTL8_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800c7c600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_CTL_REGS_TX_CNTL8_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c7c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31,
           TX0_TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c7c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31,
           TX0_TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c7c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31,
           TX0_TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_CTL_REGS_TX_CNTL9_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800c24600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_CTL_REGS_TX_CNTL9_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800c24600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_CTL_REGS_TX_CNTL9_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_CTL_REGS_TX_CNTL9_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800c24600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_CTL_REGS_TX_CNTL9_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL9_PG_TX_PATTERN_32_47(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c24600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL9_PG_TX_PATTERN_32_47,
           TX0_TXCTL_CTL_REGS_TX_CNTL9_PG_TX_PATTERN_32_47_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL9_PG_TX_PATTERN_32_47 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_CNTL9_PG_TX_PATTERN_32_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c24600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_CNTL9_PG_TX_PATTERN_32_47,
           TX0_TXCTL_CTL_REGS_TX_CNTL9_PG_TX_PATTERN_32_47_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL9_PG_TX_PATTERN_32_47 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_CNTL9_PG_TX_PATTERN_32_47(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c24600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_CNTL9_PG_TX_PATTERN_32_47,
           TX0_TXCTL_CTL_REGS_TX_CNTL9_PG_TX_PATTERN_32_47_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_CNTL9_PG_TX_PATTERN_32_47 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_CTL_REGS_TX_MODE1_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800c0c600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800c0c600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_CTL_REGS_TX_MODE1_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_CTL_REGS_TX_MODE1_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_CTL_REGS_TX_MODE1_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN,
           TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN,
           TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN,
           TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_EXBIST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c0c600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800c04600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800c04600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_8_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_8_9,
           TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_8_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_8_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_8_9,
           TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_8_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_8_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800c04600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_8_9,
           TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_8_9_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800d0c600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800d0c600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800d0c600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d0c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d0c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d0c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d0c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d0c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d0c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800d14600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800d14600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800d14600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d14600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_4,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d14600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_4,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d14600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_4,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d14600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_5,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d14600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_5,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d14600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_5,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800d1c600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800d1c600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800d1c600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d1c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d1c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d1c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d1c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d1c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d1c600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d1c600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d1c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d1c600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d1c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d1c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d1c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d1c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d1c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d1c600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d1c600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d1c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d1c600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800d24600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800d24600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800d24600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d24600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d24600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d24600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800d2c600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800d2c600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800d2c600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d2c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d2c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d2c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800cc4600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800cc4600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800cc4600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG_TX_PSAVE_FENCE_REQ_DL_IO_0_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800cc4600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG_TX_PSAVE_FENCE_REQ_DL_IO_0_15,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG_TX_PSAVE_FENCE_REQ_DL_IO_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG_TX_PSAVE_FENCE_REQ_DL_IO_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG_TX_PSAVE_FENCE_REQ_DL_IO_0_15(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800cc4600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG_TX_PSAVE_FENCE_REQ_DL_IO_0_15,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG_TX_PSAVE_FENCE_REQ_DL_IO_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG_TX_PSAVE_FENCE_REQ_DL_IO_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG_TX_PSAVE_FENCE_REQ_DL_IO_0_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800cc4600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG_TX_PSAVE_FENCE_REQ_DL_IO_0_15,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG_TX_PSAVE_FENCE_REQ_DL_IO_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG_TX_PSAVE_FENCE_REQ_DL_IO_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800ccc600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800ccc600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800ccc600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ccc600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ccc600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ccc600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800cd4600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800cd4600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800cd4600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800cd4600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800cd4600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800cd4600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800cdc600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800cdc600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800cdc600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800cdc600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800cdc600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800cdc600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800ce4600c01083f;
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
    scomt::last_scom = 0x800ce4600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800ce4600c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800ce4600c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800ce4600c01083f));
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
    FAPI_TRY(scomt::chkReg(0x800ce4600c01083f));
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
static inline fapi2::ReturnCode PREP_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL6_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800cec600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL6_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800cec600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL6_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL6_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800cec600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL6_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL6_PG_TX_PSAVE_FORCE_REQ_16_23_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800cec600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL6_PG_TX_PSAVE_FORCE_REQ_16_23_0,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL6_PG_TX_PSAVE_FORCE_REQ_16_23_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL6_PG_TX_PSAVE_FORCE_REQ_16_23_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL6_PG_TX_PSAVE_FORCE_REQ_16_23_0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800cec600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL6_PG_TX_PSAVE_FORCE_REQ_16_23_0,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL6_PG_TX_PSAVE_FORCE_REQ_16_23_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL6_PG_TX_PSAVE_FORCE_REQ_16_23_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL6_PG_TX_PSAVE_FORCE_REQ_16_23_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800cec600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL6_PG_TX_PSAVE_FORCE_REQ_16_23_0,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL6_PG_TX_PSAVE_FORCE_REQ_16_23_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL6_PG_TX_PSAVE_FORCE_REQ_16_23_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800cf4600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800cf4600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800cf4600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800cf4600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800cf4600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800cf4600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800cfc600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800cfc600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800cfc600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800cfc600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800cfc600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800cfc600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800d04600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800d04600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800d04600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d04600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d04600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d04600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d04600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d04600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d04600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1,
           TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800ca4600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800ca4600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_7(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_7(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800ca4600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT2_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800d4c600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT2_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800d4c600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT2_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT2_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800d4c600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT2_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800d54600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800d54600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800d54600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT3_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT4_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800d5c600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT4_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800d5c600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT4_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT4_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800d5c600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT4_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT5_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800d64600c01083f;
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
    scomt::last_scom = 0x800d64600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT5_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT5_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800d64600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT5_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800d6c600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800d6c600c01083f;
#endif
    return fapi2::getScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800d6c600c01083f));
#endif
    return fapi2::putScom(i_target, TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_DCC_FAIL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d6c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_DCC_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_DCC_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_DCC_FAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d6c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_DCC_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_DCC_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_DCC_FAIL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d6c600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_DCC_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_DCC_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_DCC_FAIL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d6c600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_DCC_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_DCC_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_DCC_FAIL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d6c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_DCC_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_DCC_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_DCC_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d6c600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_DCC_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_DCC_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_LS_FAIL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d6c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_LS_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_LS_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_LS_FAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d6c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_LS_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_LS_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_LS_FAIL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d6c600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_LS_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_LS_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_LS_FAIL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d6c600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_LS_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_LS_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_LS_FAIL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d6c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_LS_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_LS_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_LS_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d6c600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_LS_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_LS_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_HS_FAIL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d6c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_HS_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_HS_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_HS_FAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d6c600c01083f));
#endif
    return o_data.insertFromRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_HS_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_HS_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_HS_FAIL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d6c600c01083f));
#endif
    return o_data.setBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_HS_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_HS_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_HS_FAIL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d6c600c01083f));
#endif
    return o_data.clearBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_HS_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_HS_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_HS_FAIL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d6c600c01083f));
#endif
    return i_data.extractToRight<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_HS_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_HS_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_HS_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800d6c600c01083f));
#endif
    return i_data.getBit<TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_HS_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT6_PG_HS_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}


}
}

#endif
