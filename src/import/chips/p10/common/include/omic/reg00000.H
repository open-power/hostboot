/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omic/reg00000.H $         */
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

#ifndef __OMIC_REG00000_H_
#define __OMIC_REG00000_H_

namespace scomt
{
namespace omic
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_CNTL1_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800900600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_CNTL1_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800900600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_CNTL1_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_CNTL1_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800900600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_CNTL1_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800900600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800900600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800900600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800900600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800900600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800900600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_TIMER_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800900600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_TIMER_SEL,
           RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_TIMER_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_TIMER_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_TIMER_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800900600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_TIMER_SEL,
           RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_TIMER_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_TIMER_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_TIMER_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800900600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_TIMER_SEL,
           RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_TIMER_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL1_PG_TIMER_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800908600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800908600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_CNTL2_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_CNTL2_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG,
           RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG,
           RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG,
           RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800908600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_CNTL3_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800910600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_CNTL3_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800910600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_CNTL3_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_CNTL3_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800910600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_CNTL3_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800910600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800910600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800910600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800910600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800910600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800910600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800910600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800910600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800910600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800910600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800910600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800910600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL3_PG_FIR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_CNTL5_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800920600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_CNTL5_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800920600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_CNTL5_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_CNTL5_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800920600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_CNTL5_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_PERVASIVE_CAPT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800920600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_PERVASIVE_CAPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_PERVASIVE_CAPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_PERVASIVE_CAPT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800920600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_PERVASIVE_CAPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_PERVASIVE_CAPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_PERVASIVE_CAPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800920600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_PERVASIVE_CAPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_PERVASIVE_CAPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_PERVASIVE_CAPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800920600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_PERVASIVE_CAPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_PERVASIVE_CAPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_PERVASIVE_CAPT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800920600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_PERVASIVE_CAPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_PERVASIVE_CAPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_PERVASIVE_CAPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800920600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_PERVASIVE_CAPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_PERVASIVE_CAPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_BIST_SHARED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800920600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_BIST_SHARED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_BIST_SHARED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_BIST_SHARED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800920600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_BIST_SHARED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_BIST_SHARED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_BIST_SHARED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800920600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_BIST_SHARED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_BIST_SHARED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_BIST_SHARED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800920600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_BIST_SHARED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_BIST_SHARED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_BIST_SHARED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800920600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_BIST_SHARED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_BIST_SHARED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_BIST_SHARED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800920600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_BIST_SHARED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_CNTL5_PG_BIST_SHARED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_MODE10_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800850600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_MODE10_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800850600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE10_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_MODE10_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800850600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE10_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE10_PG_FILTER_DEPTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800850600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE10_PG_FILTER_DEPTH,
           RX0_RXCTL_CTL_REGS_RX_MODE10_PG_FILTER_DEPTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE10_PG_FILTER_DEPTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE10_PG_FILTER_DEPTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800850600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE10_PG_FILTER_DEPTH,
           RX0_RXCTL_CTL_REGS_RX_MODE10_PG_FILTER_DEPTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE10_PG_FILTER_DEPTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE10_PG_FILTER_DEPTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800850600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE10_PG_FILTER_DEPTH,
           RX0_RXCTL_CTL_REGS_RX_MODE10_PG_FILTER_DEPTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE10_PG_FILTER_DEPTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE10_PG_THRESH4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800850600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE10_PG_THRESH4,
           RX0_RXCTL_CTL_REGS_RX_MODE10_PG_THRESH4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE10_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE10_PG_THRESH4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800850600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE10_PG_THRESH4,
           RX0_RXCTL_CTL_REGS_RX_MODE10_PG_THRESH4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE10_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE10_PG_THRESH4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800850600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE10_PG_THRESH4,
           RX0_RXCTL_CTL_REGS_RX_MODE10_PG_THRESH4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE10_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800850600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG,
           RX0_RXCTL_CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800850600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG,
           RX0_RXCTL_CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800850600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG,
           RX0_RXCTL_CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE10_PG_DATA_SRC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800850600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE10_PG_DATA_SRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE10_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE10_PG_DATA_SRC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800850600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE10_PG_DATA_SRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE10_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE10_PG_DATA_SRC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800850600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_MODE10_PG_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE10_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_MODE10_PG_DATA_SRC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800850600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_MODE10_PG_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE10_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE10_PG_DATA_SRC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800850600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE10_PG_DATA_SRC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE10_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_MODE10_PG_DATA_SRC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800850600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_MODE10_PG_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE10_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_MODE11_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800858600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_MODE11_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800858600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE11_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_MODE11_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800858600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE11_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800858600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800858600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800858600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800858600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800858600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800858600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800858600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL,
           RX0_RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800858600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL,
           RX0_RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800858600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL,
           RX0_RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_MODE12_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800860600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_MODE12_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800860600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE12_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_MODE12_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800860600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE12_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800860600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC,
           RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800860600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC,
           RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800860600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC,
           RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE12_PG_RES_DAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800860600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800860600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800860600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800860600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800860600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800860600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800860600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800860600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800860600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800860600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800860600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800860600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_MODE14_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800870600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_MODE14_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800870600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE14_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_MODE14_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800870600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE14_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800870600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800870600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800870600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800870600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800870600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800870600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_MODE15_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800878600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_MODE15_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800878600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE15_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_MODE15_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800878600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE15_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE15_PG_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800878600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE15_PG_0,
           RX0_RXCTL_CTL_REGS_RX_MODE15_PG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE15_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE15_PG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800878600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE15_PG_0,
           RX0_RXCTL_CTL_REGS_RX_MODE15_PG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE15_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE15_PG_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800878600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE15_PG_0,
           RX0_RXCTL_CTL_REGS_RX_MODE15_PG_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE15_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE15_PG_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800878600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE15_PG_1,
           RX0_RXCTL_CTL_REGS_RX_MODE15_PG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE15_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE15_PG_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800878600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE15_PG_1,
           RX0_RXCTL_CTL_REGS_RX_MODE15_PG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE15_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE15_PG_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800878600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE15_PG_1,
           RX0_RXCTL_CTL_REGS_RX_MODE15_PG_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE15_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE15_PG_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800878600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE15_PG_2,
           RX0_RXCTL_CTL_REGS_RX_MODE15_PG_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE15_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE15_PG_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800878600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE15_PG_2,
           RX0_RXCTL_CTL_REGS_RX_MODE15_PG_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE15_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE15_PG_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800878600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE15_PG_2,
           RX0_RXCTL_CTL_REGS_RX_MODE15_PG_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE15_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE15_PG_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800878600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE15_PG_3,
           RX0_RXCTL_CTL_REGS_RX_MODE15_PG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE15_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE15_PG_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800878600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE15_PG_3,
           RX0_RXCTL_CTL_REGS_RX_MODE15_PG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE15_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE15_PG_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800878600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE15_PG_3,
           RX0_RXCTL_CTL_REGS_RX_MODE15_PG_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE15_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_MODE16_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800880600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_MODE16_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800880600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE16_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_MODE16_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800880600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE16_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800880600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0,
           RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800880600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0,
           RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800880600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0,
           RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800880600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH1,
           RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800880600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH1,
           RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800880600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH1,
           RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800880600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1,
           RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800880600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1,
           RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800880600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1,
           RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800880600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH2,
           RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800880600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH2,
           RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800880600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH2,
           RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_MODE17_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800888600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_MODE17_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800888600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE17_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_MODE17_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800888600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE17_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800888600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2,
           RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800888600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2,
           RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800888600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2,
           RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800888600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3,
           RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800888600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3,
           RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800888600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3,
           RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800888600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3,
           RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800888600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3,
           RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800888600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3,
           RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800888600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4,
           RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800888600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4,
           RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800888600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4,
           RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_MODE18_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800890600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_MODE18_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800890600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE18_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_MODE18_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800890600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE18_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE18_PG_HIST_BIAS_THRESH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800890600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE18_PG_HIST_BIAS_THRESH,
           RX0_RXCTL_CTL_REGS_RX_MODE18_PG_HIST_BIAS_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE18_PG_HIST_BIAS_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE18_PG_HIST_BIAS_THRESH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800890600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE18_PG_HIST_BIAS_THRESH,
           RX0_RXCTL_CTL_REGS_RX_MODE18_PG_HIST_BIAS_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE18_PG_HIST_BIAS_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE18_PG_HIST_BIAS_THRESH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800890600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE18_PG_HIST_BIAS_THRESH,
           RX0_RXCTL_CTL_REGS_RX_MODE18_PG_HIST_BIAS_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE18_PG_HIST_BIAS_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_SAMPLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800890600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_SAMPLES,
           RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_SAMPLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_SAMPLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_SAMPLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800890600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_SAMPLES,
           RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_SAMPLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_SAMPLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_SAMPLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800890600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_SAMPLES,
           RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_SAMPLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_SAMPLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_BIAS_THRESH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800890600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_BIAS_THRESH,
           RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_BIAS_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_BIAS_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_BIAS_THRESH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800890600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_BIAS_THRESH,
           RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_BIAS_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_BIAS_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_BIAS_THRESH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800890600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_BIAS_THRESH,
           RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_BIAS_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE18_PG_N1_BIAS_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_MODE19_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800898600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_MODE19_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800898600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE19_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_MODE19_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800898600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE19_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE19_PG_HIST_BIAS_THRESH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800898600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE19_PG_HIST_BIAS_THRESH,
           RX0_RXCTL_CTL_REGS_RX_MODE19_PG_HIST_BIAS_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE19_PG_HIST_BIAS_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE19_PG_HIST_BIAS_THRESH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800898600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE19_PG_HIST_BIAS_THRESH,
           RX0_RXCTL_CTL_REGS_RX_MODE19_PG_HIST_BIAS_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE19_PG_HIST_BIAS_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE19_PG_HIST_BIAS_THRESH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800898600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE19_PG_HIST_BIAS_THRESH,
           RX0_RXCTL_CTL_REGS_RX_MODE19_PG_HIST_BIAS_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE19_PG_HIST_BIAS_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_SAMPLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800898600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_SAMPLES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_SAMPLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_SAMPLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800898600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_SAMPLES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_SAMPLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_SAMPLES(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800898600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_SAMPLES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_SAMPLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_SAMPLES(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800898600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_SAMPLES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_SAMPLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_SAMPLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800898600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_SAMPLES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_SAMPLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_SAMPLES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800898600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_SAMPLES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_SAMPLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_BIAS_THRESH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800898600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_BIAS_THRESH,
           RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_BIAS_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_BIAS_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_BIAS_THRESH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800898600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_BIAS_THRESH,
           RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_BIAS_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_BIAS_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_BIAS_THRESH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800898600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_BIAS_THRESH,
           RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_BIAS_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N1_BIAS_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N2_SAMPLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800898600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N2_SAMPLES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N2_SAMPLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N2_SAMPLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800898600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N2_SAMPLES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N2_SAMPLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N2_SAMPLES(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800898600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N2_SAMPLES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N2_SAMPLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N2_SAMPLES(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800898600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N2_SAMPLES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N2_SAMPLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N2_SAMPLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800898600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N2_SAMPLES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N2_SAMPLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N2_SAMPLES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800898600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N2_SAMPLES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE19_PG_N2_SAMPLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_MODE1_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800808600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_MODE1_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800808600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE1_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_MODE1_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800808600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE1_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800808600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN,
           RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800808600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN,
           RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800808600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN,
           RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800808600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800808600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800808600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800808600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800808600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800808600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_MODE20_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8008a0600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_MODE20_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8008a0600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE20_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_MODE20_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x8008a0600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE20_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE20_PG_AMP_HYST_START(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8008a0600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE20_PG_AMP_HYST_START,
           RX0_RXCTL_CTL_REGS_RX_MODE20_PG_AMP_HYST_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE20_PG_AMP_HYST_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE20_PG_AMP_HYST_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8008a0600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE20_PG_AMP_HYST_START,
           RX0_RXCTL_CTL_REGS_RX_MODE20_PG_AMP_HYST_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE20_PG_AMP_HYST_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE20_PG_AMP_HYST_START(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8008a0600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE20_PG_AMP_HYST_START,
           RX0_RXCTL_CTL_REGS_RX_MODE20_PG_AMP_HYST_START_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE20_PG_AMP_HYST_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE20_PG_LOFF_HYST_START(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8008a0600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE20_PG_LOFF_HYST_START,
           RX0_RXCTL_CTL_REGS_RX_MODE20_PG_LOFF_HYST_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE20_PG_LOFF_HYST_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE20_PG_LOFF_HYST_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8008a0600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE20_PG_LOFF_HYST_START,
           RX0_RXCTL_CTL_REGS_RX_MODE20_PG_LOFF_HYST_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE20_PG_LOFF_HYST_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE20_PG_LOFF_HYST_START(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8008a0600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE20_PG_LOFF_HYST_START,
           RX0_RXCTL_CTL_REGS_RX_MODE20_PG_LOFF_HYST_START_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE20_PG_LOFF_HYST_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_MODE21_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8008a8600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_MODE21_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8008a8600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE21_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_MODE21_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x8008a8600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE21_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8008a8600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN,
           RX0_RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8008a8600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN,
           RX0_RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8008a8600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN,
           RX0_RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_MODE2_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800810600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_MODE2_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800810600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE2_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_MODE2_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800810600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE2_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800810600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800810600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800810600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800810600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800810600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800810600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800810600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT,
           RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800810600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT,
           RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800810600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT,
           RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800810600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK,
           RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800810600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK,
           RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800810600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK,
           RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800810600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800810600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800810600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800810600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800810600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800810600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_MODE3_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800818600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_MODE3_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800818600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE3_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_MODE3_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800818600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE3_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FILTER_DEPTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800818600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FILTER_DEPTH,
           RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FILTER_DEPTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FILTER_DEPTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FILTER_DEPTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800818600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FILTER_DEPTH,
           RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FILTER_DEPTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FILTER_DEPTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FILTER_DEPTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800818600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FILTER_DEPTH,
           RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FILTER_DEPTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FILTER_DEPTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_THRESH4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800818600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE3_PG_THRESH4,
           RX0_RXCTL_CTL_REGS_RX_MODE3_PG_THRESH4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE3_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_THRESH4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800818600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE3_PG_THRESH4,
           RX0_RXCTL_CTL_REGS_RX_MODE3_PG_THRESH4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE3_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_THRESH4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800818600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE3_PG_THRESH4,
           RX0_RXCTL_CTL_REGS_RX_MODE3_PG_THRESH4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE3_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800818600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG,
           RX0_RXCTL_CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800818600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG,
           RX0_RXCTL_CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800818600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG,
           RX0_RXCTL_CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_DATA_SRC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800818600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE3_PG_DATA_SRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE3_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_DATA_SRC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800818600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE3_PG_DATA_SRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE3_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_DATA_SRC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800818600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_MODE3_PG_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE3_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_DATA_SRC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800818600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_MODE3_PG_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE3_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_DATA_SRC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800818600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE3_PG_DATA_SRC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE3_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_DATA_SRC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800818600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_MODE3_PG_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE3_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FORMAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800818600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FORMAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FORMAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FORMAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800818600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FORMAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FORMAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FORMAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800818600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FORMAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FORMAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FORMAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800818600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FORMAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FORMAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FORMAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800818600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FORMAT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FORMAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FORMAT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800818600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FORMAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE3_PG_FORMAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_MODE4_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800820600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_MODE4_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800820600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE4_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_MODE4_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800820600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE4_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800820600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC0,
           RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800820600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC0,
           RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800820600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC0,
           RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800820600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC0,
           RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800820600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC0,
           RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800820600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC0,
           RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800820600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC1,
           RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800820600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC1,
           RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800820600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC1,
           RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE4_PG_INC1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800820600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC1,
           RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800820600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC1,
           RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800820600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC1,
           RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE4_PG_DEC1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_MODE5_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800828600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_MODE5_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800828600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE5_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_MODE5_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800828600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE5_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800828600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0,
           RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800828600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0,
           RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800828600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0,
           RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800828600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1,
           RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800828600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1,
           RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800828600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1,
           RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800828600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1,
           RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800828600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1,
           RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800828600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1,
           RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800828600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2,
           RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800828600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2,
           RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800828600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2,
           RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE5_PG_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_MODE6_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800830600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_MODE6_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800830600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE6_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_MODE6_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800830600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE6_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800830600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2,
           RX0_RXCTL_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800830600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2,
           RX0_RXCTL_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800830600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2,
           RX0_RXCTL_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE6_PG_THRESH3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800830600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE6_PG_THRESH3,
           RX0_RXCTL_CTL_REGS_RX_MODE6_PG_THRESH3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE6_PG_THRESH3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE6_PG_THRESH3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800830600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE6_PG_THRESH3,
           RX0_RXCTL_CTL_REGS_RX_MODE6_PG_THRESH3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE6_PG_THRESH3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE6_PG_THRESH3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800830600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE6_PG_THRESH3,
           RX0_RXCTL_CTL_REGS_RX_MODE6_PG_THRESH3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE6_PG_THRESH3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800830600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3,
           RX0_RXCTL_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800830600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3,
           RX0_RXCTL_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800830600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3,
           RX0_RXCTL_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE6_PG_THRESH4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800830600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE6_PG_THRESH4,
           RX0_RXCTL_CTL_REGS_RX_MODE6_PG_THRESH4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE6_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE6_PG_THRESH4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800830600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE6_PG_THRESH4,
           RX0_RXCTL_CTL_REGS_RX_MODE6_PG_THRESH4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE6_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE6_PG_THRESH4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800830600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE6_PG_THRESH4,
           RX0_RXCTL_CTL_REGS_RX_MODE6_PG_THRESH4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE6_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_MODE7_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800838600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_MODE7_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800838600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE7_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_MODE7_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800838600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE7_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE7_PG_AMP_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800838600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE7_PG_AMP_TIMEOUT,
           RX0_RXCTL_CTL_REGS_RX_MODE7_PG_AMP_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE7_PG_AMP_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE7_PG_AMP_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800838600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE7_PG_AMP_TIMEOUT,
           RX0_RXCTL_CTL_REGS_RX_MODE7_PG_AMP_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE7_PG_AMP_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE7_PG_AMP_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800838600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE7_PG_AMP_TIMEOUT,
           RX0_RXCTL_CTL_REGS_RX_MODE7_PG_AMP_TIMEOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE7_PG_AMP_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE7_PG_LOFF_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800838600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE7_PG_LOFF_TIMEOUT,
           RX0_RXCTL_CTL_REGS_RX_MODE7_PG_LOFF_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE7_PG_LOFF_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE7_PG_LOFF_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800838600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE7_PG_LOFF_TIMEOUT,
           RX0_RXCTL_CTL_REGS_RX_MODE7_PG_LOFF_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE7_PG_LOFF_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE7_PG_LOFF_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800838600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE7_PG_LOFF_TIMEOUT,
           RX0_RXCTL_CTL_REGS_RX_MODE7_PG_LOFF_TIMEOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE7_PG_LOFF_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE7_PG_CTLE_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800838600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE7_PG_CTLE_TIMEOUT,
           RX0_RXCTL_CTL_REGS_RX_MODE7_PG_CTLE_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE7_PG_CTLE_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE7_PG_CTLE_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800838600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE7_PG_CTLE_TIMEOUT,
           RX0_RXCTL_CTL_REGS_RX_MODE7_PG_CTLE_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE7_PG_CTLE_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE7_PG_CTLE_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800838600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE7_PG_CTLE_TIMEOUT,
           RX0_RXCTL_CTL_REGS_RX_MODE7_PG_CTLE_TIMEOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE7_PG_CTLE_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE7_PG_LTE_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800838600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE7_PG_LTE_TIMEOUT,
           RX0_RXCTL_CTL_REGS_RX_MODE7_PG_LTE_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE7_PG_LTE_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE7_PG_LTE_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800838600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE7_PG_LTE_TIMEOUT,
           RX0_RXCTL_CTL_REGS_RX_MODE7_PG_LTE_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE7_PG_LTE_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE7_PG_LTE_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800838600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE7_PG_LTE_TIMEOUT,
           RX0_RXCTL_CTL_REGS_RX_MODE7_PG_LTE_TIMEOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE7_PG_LTE_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_MODE8_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800840600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_MODE8_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800840600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE8_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_MODE8_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800840600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE8_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE8_PG_RX_BO_TIME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800840600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE8_PG_RX_BO_TIME,
           RX0_RXCTL_CTL_REGS_RX_MODE8_PG_RX_BO_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE8_PG_RX_BO_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE8_PG_RX_BO_TIME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800840600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE8_PG_RX_BO_TIME,
           RX0_RXCTL_CTL_REGS_RX_MODE8_PG_RX_BO_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE8_PG_RX_BO_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE8_PG_RX_BO_TIME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800840600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE8_PG_RX_BO_TIME,
           RX0_RXCTL_CTL_REGS_RX_MODE8_PG_RX_BO_TIME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE8_PG_RX_BO_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_MODE9_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800848600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_MODE9_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800848600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE9_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_MODE9_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800848600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_MODE9_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800848600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC2,
           RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800848600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC2,
           RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800848600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC2,
           RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800848600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC2,
           RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800848600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC2,
           RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800848600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC2,
           RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800848600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC3,
           RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800848600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC3,
           RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800848600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC3,
           RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800848600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC3,
           RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800848600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC3,
           RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800848600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC3,
           RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_FIR1_ERROR_INJECT_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800938600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_FIR1_ERROR_INJECT_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800938600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_FIR1_ERROR_INJECT_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_FIR1_ERROR_INJECT_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800938600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_FIR1_ERROR_INJECT_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800938600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ,
           RX0_RXCTL_CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800938600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ,
           RX0_RXCTL_CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800938600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ,
           RX0_RXCTL_CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_FIR1_MASK_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800930600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_FIR1_MASK_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800930600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_FIR1_MASK_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_FIR1_MASK_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800930600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_FIR1_MASK_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800930600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK,
           RX0_RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800930600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK,
           RX0_RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800930600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK,
           RX0_RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_FIR1_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800928600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_FIR1_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800928600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_FIR1_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_FIR1_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800928600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_FIR1_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800800600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800800600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800800600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8009d0600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8009d0600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT10_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x8009d0600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT10_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009d0600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0,
           RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009d0600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0,
           RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009d0600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0,
           RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_DATASM_REGS_RX_CNT11_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8009d8600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_DATASM_REGS_RX_CNT11_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8009d8600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT11_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_DATASM_REGS_RX_CNT11_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x8009d8600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT11_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009d8600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15,
           RX0_RXCTL_DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009d8600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15,
           RX0_RXCTL_DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009d8600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15,
           RX0_RXCTL_DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_DATASM_REGS_RX_CNT12_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8009e0600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_DATASM_REGS_RX_CNT12_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8009e0600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT12_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_DATASM_REGS_RX_CNT12_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x8009e0600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT12_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009e0600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23,
           RX0_RXCTL_DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009e0600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23,
           RX0_RXCTL_DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009e0600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23,
           RX0_RXCTL_DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8009e8600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8009e8600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT13_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x8009e8600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT13_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009e8600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009e8600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009e8600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009e8600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009e8600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009e8600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009e8600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009e8600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009e8600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009e8600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009e8600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009e8600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009e8600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009e8600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009e8600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009e8600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009e8600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009e8600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_DATASM_REGS_RX_CNT14_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8009f0600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_DATASM_REGS_RX_CNT14_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8009f0600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT14_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_DATASM_REGS_RX_CNT14_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x8009f0600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT14_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_0_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009f0600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_0_SEL,
           RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_0_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009f0600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_0_SEL,
           RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_0_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009f0600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_0_SEL,
           RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_0_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_1_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009f0600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_1_SEL,
           RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_1_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_1_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009f0600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_1_SEL,
           RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_1_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_1_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009f0600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_1_SEL,
           RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_1_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_2_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009f0600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_2_SEL,
           RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_2_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_2_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009f0600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_2_SEL,
           RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_2_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_2_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009f0600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_2_SEL,
           RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_2_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_DATASM_REGS_RX_CNT15_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8009f8600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_DATASM_REGS_RX_CNT15_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8009f8600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT15_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_DATASM_REGS_RX_CNT15_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x8009f8600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT15_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009f8600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL,
           RX0_RXCTL_DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009f8600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL,
           RX0_RXCTL_DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8009f8600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL,
           RX0_RXCTL_DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_DATASM_REGS_RX_CNT16_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a00600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_DATASM_REGS_RX_CNT16_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a00600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT16_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_DATASM_REGS_RX_CNT16_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800a00600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT16_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a00600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_0,
           RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a00600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_0,
           RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a00600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_0,
           RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a00600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_1,
           RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a00600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_1,
           RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a00600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_1,
           RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_DATASM_REGS_RX_CNT17_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a08600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_DATASM_REGS_RX_CNT17_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a08600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT17_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_DATASM_REGS_RX_CNT17_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800a08600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT17_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT17_PG_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a08600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT17_PG_2,
           RX0_RXCTL_DATASM_REGS_RX_CNT17_PG_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT17_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT17_PG_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a08600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT17_PG_2,
           RX0_RXCTL_DATASM_REGS_RX_CNT17_PG_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT17_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT17_PG_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a08600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT17_PG_2,
           RX0_RXCTL_DATASM_REGS_RX_CNT17_PG_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT17_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT17_PG_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a08600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT17_PG_3,
           RX0_RXCTL_DATASM_REGS_RX_CNT17_PG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT17_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT17_PG_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a08600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT17_PG_3,
           RX0_RXCTL_DATASM_REGS_RX_CNT17_PG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT17_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT17_PG_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a08600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT17_PG_3,
           RX0_RXCTL_DATASM_REGS_RX_CNT17_PG_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT17_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_DATASM_REGS_RX_CNT18_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a10600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_DATASM_REGS_RX_CNT18_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a10600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT18_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_DATASM_REGS_RX_CNT18_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800a10600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT18_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a10600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_4,
           RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a10600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_4,
           RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a10600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_4,
           RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a10600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_5,
           RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a10600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_5,
           RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a10600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_5,
           RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_DATASM_REGS_RX_CNT19_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a18600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_DATASM_REGS_RX_CNT19_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a18600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT19_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_DATASM_REGS_RX_CNT19_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800a18600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT19_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT19_PG_RX_PSAVE_SUBSET6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a18600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT19_PG_RX_PSAVE_SUBSET6,
           RX0_RXCTL_DATASM_REGS_RX_CNT19_PG_RX_PSAVE_SUBSET6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT19_PG_RX_PSAVE_SUBSET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT19_PG_RX_PSAVE_SUBSET6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a18600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT19_PG_RX_PSAVE_SUBSET6,
           RX0_RXCTL_DATASM_REGS_RX_CNT19_PG_RX_PSAVE_SUBSET6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT19_PG_RX_PSAVE_SUBSET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT19_PG_RX_PSAVE_SUBSET6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a18600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT19_PG_RX_PSAVE_SUBSET6,
           RX0_RXCTL_DATASM_REGS_RX_CNT19_PG_RX_PSAVE_SUBSET6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT19_PG_RX_PSAVE_SUBSET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a20600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a20600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT20_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT20_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME,
           RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME,
           RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME,
           RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME,
           RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME,
           RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME,
           RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a20600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_DATASM_REGS_RX_CNT21_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a28600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_DATASM_REGS_RX_CNT21_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a28600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT21_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_DATASM_REGS_RX_CNT21_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800a28600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT21_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a28600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a28600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a28600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a28600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a28600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a28600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a30600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a30600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT22_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT22_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_GAIN_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_GAIN_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_GAIN_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_GAIN_CHECK_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_GAIN_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_GAIN_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_GAIN_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_GAIN_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_GAIN_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_GAIN_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_GAIN_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_GAIN_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_GAIN_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_GAIN_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_GAIN_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_GAIN_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_GAIN_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_GAIN_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LATCHOFF_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LATCHOFF_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LATCHOFF_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LATCHOFF_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LATCHOFF_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LATCHOFF_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LATCHOFF_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LATCHOFF_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LATCHOFF_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LATCHOFF_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LATCHOFF_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LATCHOFF_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LATCHOFF_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LATCHOFF_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LATCHOFF_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LATCHOFF_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LATCHOFF_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LATCHOFF_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_POFF_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_POFF_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_POFF_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_POFF_CHECK_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_POFF_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_POFF_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_POFF_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_POFF_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_POFF_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_POFF_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_POFF_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_POFF_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_POFF_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_POFF_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_POFF_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_POFF_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_POFF_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_EOFF_POFF_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_PEAK_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_PEAK_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_PEAK_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_PEAK_CHECK_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_PEAK_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_PEAK_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_PEAK_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_PEAK_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_PEAK_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_PEAK_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_PEAK_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_PEAK_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_PEAK_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_PEAK_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_PEAK_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_PEAK_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_PEAK_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_CTLE_PEAK_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_GAIN_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_GAIN_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_GAIN_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_GAIN_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_GAIN_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_GAIN_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_GAIN_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_GAIN_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_GAIN_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_GAIN_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_GAIN_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_GAIN_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_GAIN_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_GAIN_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_GAIN_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_GAIN_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_GAIN_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_GAIN_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_FREQ_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_FREQ_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_FREQ_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_FREQ_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_FREQ_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_FREQ_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_FREQ_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_FREQ_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_FREQ_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_FREQ_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_FREQ_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_FREQ_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_FREQ_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_FREQ_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_FREQ_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_FREQ_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_FREQ_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LTE_FREQ_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BANK_SYNC_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BANK_SYNC_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BANK_SYNC_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BANK_SYNC_CHECK_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BANK_SYNC_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BANK_SYNC_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BANK_SYNC_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BANK_SYNC_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BANK_SYNC_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BANK_SYNC_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BANK_SYNC_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BANK_SYNC_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BANK_SYNC_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BANK_SYNC_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BANK_SYNC_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BANK_SYNC_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BANK_SYNC_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BANK_SYNC_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_QUAD_PHASE_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_QUAD_PHASE_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_QUAD_PHASE_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_QUAD_PHASE_CHECK_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_QUAD_PHASE_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_QUAD_PHASE_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_QUAD_PHASE_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_QUAD_PHASE_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_QUAD_PHASE_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_QUAD_PHASE_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_QUAD_PHASE_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_QUAD_PHASE_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_QUAD_PHASE_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_QUAD_PHASE_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_QUAD_PHASE_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_QUAD_PHASE_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_QUAD_PHASE_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_QUAD_PHASE_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_H1_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_H1_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_H1_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_H1_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_H1_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_H1_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_H1_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_H1_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_H1_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_H1_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_H1_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_H1_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_H1_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_H1_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_H1_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_H1_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_H1_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_H1_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DFE_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DDC_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DDC_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DDC_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DDC_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DDC_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DDC_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DDC_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DDC_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DDC_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DDC_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DDC_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DDC_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DDC_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DDC_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DDC_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DDC_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DDC_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_DDC_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BER_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BER_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BER_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BER_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BER_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BER_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BER_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BER_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BER_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BER_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BER_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BER_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BER_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BER_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BER_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BER_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BER_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_BER_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LINK_LAYER_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LINK_LAYER_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LINK_LAYER_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LINK_LAYER_CHECK_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LINK_LAYER_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LINK_LAYER_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LINK_LAYER_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LINK_LAYER_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LINK_LAYER_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LINK_LAYER_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LINK_LAYER_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LINK_LAYER_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LINK_LAYER_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LINK_LAYER_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LINK_LAYER_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LINK_LAYER_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LINK_LAYER_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_RX_LINK_LAYER_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_SYSTEM_DFT_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_SYSTEM_DFT_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_SYSTEM_DFT_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_SYSTEM_DFT_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_SYSTEM_DFT_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_SYSTEM_DFT_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_SYSTEM_DFT_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.setBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_SYSTEM_DFT_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_SYSTEM_DFT_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_SYSTEM_DFT_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return o_data.clearBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_SYSTEM_DFT_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_SYSTEM_DFT_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_SYSTEM_DFT_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_SYSTEM_DFT_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_SYSTEM_DFT_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_SYSTEM_DFT_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a30600c01083f));
#endif
    return i_data.getBit<RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_SYSTEM_DFT_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT22_PG_SYSTEM_DFT_CHECK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_DATASM_REGS_RX_CNT23_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a38600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_DATASM_REGS_RX_CNT23_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a38600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT23_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_DATASM_REGS_RX_CNT23_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800a38600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT23_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a38600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15,
           RX0_RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a38600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15,
           RX0_RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a38600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15,
           RX0_RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_DATASM_REGS_RX_CNT24_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a40600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_DATASM_REGS_RX_CNT24_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a40600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT24_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_DATASM_REGS_RX_CNT24_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800a40600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT24_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a40600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23,
           RX0_RXCTL_DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a40600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23,
           RX0_RXCTL_DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a40600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23,
           RX0_RXCTL_DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_DATASM_REGS_RX_CNT25_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a48600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_DATASM_REGS_RX_CNT25_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a48600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT25_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_DATASM_REGS_RX_CNT25_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800a48600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT25_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a48600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15,
           RX0_RXCTL_DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a48600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15,
           RX0_RXCTL_DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a48600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15,
           RX0_RXCTL_DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_DATASM_REGS_RX_CNT26_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a50600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_DATASM_REGS_RX_CNT26_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a50600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT26_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_DATASM_REGS_RX_CNT26_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800a50600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT26_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a50600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23,
           RX0_RXCTL_DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a50600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23,
           RX0_RXCTL_DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a50600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23,
           RX0_RXCTL_DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_DATASM_REGS_RX_CNT27_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a58600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_DATASM_REGS_RX_CNT27_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a58600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT27_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_DATASM_REGS_RX_CNT27_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800a58600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT27_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT27_PG_RX_A_LANE_DONE_0_16(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a58600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT27_PG_RX_A_LANE_DONE_0_16,
           RX0_RXCTL_DATASM_REGS_RX_CNT27_PG_RX_A_LANE_DONE_0_16_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT27_PG_RX_A_LANE_DONE_0_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT27_PG_RX_A_LANE_DONE_0_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a58600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT27_PG_RX_A_LANE_DONE_0_16,
           RX0_RXCTL_DATASM_REGS_RX_CNT27_PG_RX_A_LANE_DONE_0_16_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT27_PG_RX_A_LANE_DONE_0_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT27_PG_RX_A_LANE_DONE_0_16(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a58600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT27_PG_RX_A_LANE_DONE_0_16,
           RX0_RXCTL_DATASM_REGS_RX_CNT27_PG_RX_A_LANE_DONE_0_16_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT27_PG_RX_A_LANE_DONE_0_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_DATASM_REGS_RX_CNT28_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a60600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_DATASM_REGS_RX_CNT28_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a60600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT28_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_DATASM_REGS_RX_CNT28_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800a60600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT28_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a60600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23,
           RX0_RXCTL_DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a60600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23,
           RX0_RXCTL_DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a60600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23,
           RX0_RXCTL_DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_DATASM_REGS_RX_CNT29_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a68600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_DATASM_REGS_RX_CNT29_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a68600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT29_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_DATASM_REGS_RX_CNT29_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800a68600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT29_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT29_PG_RX_B_LANE_DONE_0_16(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a68600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT29_PG_RX_B_LANE_DONE_0_16,
           RX0_RXCTL_DATASM_REGS_RX_CNT29_PG_RX_B_LANE_DONE_0_16_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT29_PG_RX_B_LANE_DONE_0_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT29_PG_RX_B_LANE_DONE_0_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a68600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT29_PG_RX_B_LANE_DONE_0_16,
           RX0_RXCTL_DATASM_REGS_RX_CNT29_PG_RX_B_LANE_DONE_0_16_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT29_PG_RX_B_LANE_DONE_0_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT29_PG_RX_B_LANE_DONE_0_16(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a68600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT29_PG_RX_B_LANE_DONE_0_16,
           RX0_RXCTL_DATASM_REGS_RX_CNT29_PG_RX_B_LANE_DONE_0_16_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT29_PG_RX_B_LANE_DONE_0_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a70600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a70600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT30_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800a70600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT30_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a70600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23,
           RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a70600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23,
           RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a70600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23,
           RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RX0_RXCTL_DATASM_REGS_RX_CNT31_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a78600c01083f;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RX0_RXCTL_DATASM_REGS_RX_CNT31_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x800a78600c01083f;
#endif
    return fapi2::getScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT31_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RX0_RXCTL_DATASM_REGS_RX_CNT31_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x800a78600c01083f));
#endif
    return fapi2::putScom(i_target, RX0_RXCTL_DATASM_REGS_RX_CNT31_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT31_PG_RX_SECTION_FAIL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a78600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT31_PG_RX_SECTION_FAIL,
           RX0_RXCTL_DATASM_REGS_RX_CNT31_PG_RX_SECTION_FAIL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT31_PG_RX_SECTION_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RX0_RXCTL_DATASM_REGS_RX_CNT31_PG_RX_SECTION_FAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a78600c01083f));
#endif
    return o_data.insertFromRight<RX0_RXCTL_DATASM_REGS_RX_CNT31_PG_RX_SECTION_FAIL,
           RX0_RXCTL_DATASM_REGS_RX_CNT31_PG_RX_SECTION_FAIL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT31_PG_RX_SECTION_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RX0_RXCTL_DATASM_REGS_RX_CNT31_PG_RX_SECTION_FAIL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x800a78600c01083f));
#endif
    return i_data.extractToRight<RX0_RXCTL_DATASM_REGS_RX_CNT31_PG_RX_SECTION_FAIL,
           RX0_RXCTL_DATASM_REGS_RX_CNT31_PG_RX_SECTION_FAIL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RX0_RXCTL_DATASM_REGS_RX_CNT31_PG_RX_SECTION_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}


}
}

#endif
