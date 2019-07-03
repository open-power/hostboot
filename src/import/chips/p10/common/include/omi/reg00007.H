/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omi/reg00007.H $          */
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

#ifndef __OMI_REG00007_H_
#define __OMI_REG00007_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IORESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IORESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IORESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IORESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IORESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IORESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK,
           RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK,
           RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK,
           RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR,
           RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR,
           RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR,
           RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE,
           RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE,
           RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE,
           RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE,
           RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE,
           RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE,
           RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_3_RX_BIT_REGS_STAT3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_BIT_REGS_STAT3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_3_RX_BIT_REGS_STAT3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_BIT_REGS_STAT3_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_3_RX_BIT_REGS_STAT3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_3_RX_BIT_REGS_STAT3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_STAT3_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_3_RX_BIT_REGS_STAT3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110,
           RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110,
           RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110,
           RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000,
           RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000,
           RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000,
           RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010,
           RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010,
           RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010,
           RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001,
           RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001,
           RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001,
           RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_EN,
           TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_EN,
           TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_EN,
           TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_SEL,
           TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_SEL,
           TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_SEL,
           TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL12_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_EN,
           TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_EN,
           TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_EN,
           TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_SEL,
           TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_SEL,
           TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_SEL,
           TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL22_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_EN,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_EN,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_EN,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_SEL,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_SEL,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_SEL,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL28_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_EN,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_EN,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_EN,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_SEL,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_SEL,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_SEL,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_FIR_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_PDWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_PDWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_PDWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_INVERT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_INVERT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE,
           TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS,
           TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS,
           TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS,
           TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL,
           TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL,
           TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL,
           TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN,
           TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN,
           TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN,
           TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_EN,
           TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_EN,
           TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_EN,
           TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_SEL,
           TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_SEL,
           TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_SEL,
           TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL19_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN,
           TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN,
           TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN,
           TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_EN,
           TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_EN,
           TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_EN,
           TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_SEL,
           TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_SEL,
           TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_SEL,
           TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL13_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN,
           TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN,
           TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN,
           TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.setBit<TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.getBit<TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.setBit<TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.getBit<TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_1_DD_2_TX_BIT_REGS_CNTL25_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_1_DD_2_TX_BIT_REGS_CNTL25_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_1_DD_2_TX_BIT_REGS_CNTL25_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL25_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_1_DD_2_TX_BIT_REGS_CNTL25_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL25_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_2_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           TXPACKS_1_DD_2_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL25_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_2_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           TXPACKS_1_DD_2_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL25_PL));
#endif
    return i_data.extractToRight<TXPACKS_1_DD_2_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           TXPACKS_1_DD_2_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL_EN,
           TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL_EN,
           TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL));
#endif
    return i_data.extractToRight<TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL_EN,
           TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL_SEL,
           TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL_SEL,
           TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL));
#endif
    return i_data.extractToRight<TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL_SEL,
           TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_CNTL4_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_1_DD_2_TX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_1_DD_2_TX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_1_DD_2_TX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_1_DD_2_TX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_1_DD_2_TX_BIT_REGS_FIR_MASK_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_1_DD_2_TX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_1_DD_2_TX_BIT_REGS_FIR_MASK_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_2_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK,
           TXPACKS_1_DD_2_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_2_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK,
           TXPACKS_1_DD_2_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_1_DD_2_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return i_data.extractToRight<TXPACKS_1_DD_2_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK,
           TXPACKS_1_DD_2_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_1_DD_2_TX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_1_DD_2_TX_BIT_REGS_FIR_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_1_DD_2_TX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_1_DD_2_TX_BIT_REGS_FIR_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_1_DD_2_TX_BIT_REGS_FIR_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_1_DD_2_TX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_FIR_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_1_DD_2_TX_BIT_REGS_FIR_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY,
           TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY,
           TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY,
           TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL,
           TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL,
           TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL,
           TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_1_DD_3_TX_BIT_REGS_CNTL9_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_1_DD_3_TX_BIT_REGS_CNTL9_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_1_DD_3_TX_BIT_REGS_CNTL9_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_1_DD_3_TX_BIT_REGS_CNTL9_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_1_DD_3_TX_BIT_REGS_CNTL9_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_1_DD_3_TX_BIT_REGS_CNTL9_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_3_TX_BIT_REGS_CNTL9_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_1_DD_3_TX_BIT_REGS_CNTL9_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_3_TX_BIT_REGS_CNTL9_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN,
           TXPACKS_1_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TXPACKS_1_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_3_TX_BIT_REGS_CNTL9_PL));
#endif
    return o_data.insertFromRight<TXPACKS_1_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN,
           TXPACKS_1_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TXPACKS_1_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_1_DD_3_TX_BIT_REGS_CNTL9_PL));
#endif
    return i_data.extractToRight<TXPACKS_1_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN,
           TXPACKS_1_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TXPACKS_1_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
