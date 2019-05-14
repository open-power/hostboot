/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00036.H $         */
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

#ifndef __IOHS_REG00036_H_
#define __IOHS_REG00036_H_

namespace scomt
{
namespace iohs
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT,
           IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT,
           IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL));
#endif
    return i_data.extractToRight<IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT,
           IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT,
           IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT,
           IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL));
#endif
    return i_data.extractToRight<IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT,
           IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_COARSE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_COARSE,
           IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_COARSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_COARSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_COARSE,
           IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_COARSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_COARSE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_COARSE,
           IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_COARSE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_COARSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_GAIN,
           IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_GAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_GAIN,
           IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_GAIN,
           IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_GAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL13_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL,
           IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL,
           IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL,
           IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ,
           IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ,
           IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ,
           IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_RX_BIT_REGS_CNTLX5_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_BIT_REGS_CNTLX5_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_RX_BIT_REGS_CNTLX5_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_BIT_REGS_CNTLX5_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_RX_BIT_REGS_CNTLX5_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_RX_BIT_REGS_CNTLX5_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_RX_BIT_REGS_CNTLX5_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL,
           IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL,
           IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL,
           IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_DATA,
           IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_DATA,
           IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_DATA,
           IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_EDGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_EDGE,
           IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_EDGE,
           IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_EDGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_EDGE,
           IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_CNTL14_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_COARSE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_COARSE,
           IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_COARSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_COARSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_COARSE,
           IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_COARSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_COARSE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_COARSE,
           IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_COARSE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_COARSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_GAIN,
           IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_GAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_GAIN,
           IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_GAIN,
           IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_GAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL6_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_FILTER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_FILTER,
           IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_FILTER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_FILTER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_FILTER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_FILTER,
           IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_FILTER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_FILTER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_FILTER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_FILTER,
           IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_FILTER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_FILTER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_TERM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_TERM,
           IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_TERM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_TERM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_TERM,
           IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_TERM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_TERM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_TERM,
           IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_TERM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE3_PL_TERM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_BIT_REGS_STAT5_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_BIT_REGS_STAT5_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_BIT_REGS_STAT5_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_BIT_REGS_STAT5_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_BIT_REGS_STAT5_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_BIT_REGS_STAT5_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_STAT5_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_BIT_REGS_STAT5_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK,
           IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK,
           IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK,
           IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG;
#endif
    return fapi2::getScom(i_target, IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG));
#endif
    return fapi2::putScom(i_target, IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL,
           IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL,
           IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL,
           IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG;
#endif
    return fapi2::getScom(i_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG));
#endif
    return fapi2::putScom(i_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15,
           IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15,
           IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15,
           IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT5_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT5_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT5_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT5_PG;
#endif
    return fapi2::getScom(i_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT5_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT5_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT5_PG));
#endif
    return fapi2::putScom(i_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT5_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ,
           IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ,
           IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ,
           IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK,
           IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK,
           IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK,
           IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_EN,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_EN,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_EN,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_SEL,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_SEL,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_SEL,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL20_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_I_TUNE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_I_TUNE,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_I_TUNE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_I_TUNE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_I_TUNE,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_I_TUNE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_I_TUNE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_I_TUNE,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_I_TUNE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_Q_TUNE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_Q_TUNE,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_Q_TUNE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_Q_TUNE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_Q_TUNE,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_Q_TUNE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_Q_TUNE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_Q_TUNE,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL16_PL_Q_TUNE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_EN,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_EN,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_EN,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_SEL,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_SEL,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_SEL,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL7_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
