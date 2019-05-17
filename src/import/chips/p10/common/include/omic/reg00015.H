/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omic/reg00015.H $         */
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

#ifndef __OMIC_REG00015_H_
#define __OMIC_REG00015_H_

namespace scomt
{
namespace omic
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_CNTL2_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_CNTL2_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_CNTL2_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_CNTL2_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_CNTL2_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_CNTL2_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_CNTL2_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG,
           CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG,
           CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG,
           CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL2_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_MODE11_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE11_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_MODE11_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE11_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_MODE11_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_MODE11_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE11_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_MODE11_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE11_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE11_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE11_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE11_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE11_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE11_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE11_PG_AMP_START_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE11_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE11_PG_AMP_START_VAL,
           CTL_REGS_RX_MODE11_PG_AMP_START_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE11_PG_AMP_START_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE11_PG_AMP_START_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE11_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE11_PG_AMP_START_VAL,
           CTL_REGS_RX_MODE11_PG_AMP_START_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE11_PG_AMP_START_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE11_PG_AMP_START_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE11_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE11_PG_AMP_START_VAL,
           CTL_REGS_RX_MODE11_PG_AMP_START_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE11_PG_AMP_START_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_MODE21_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE21_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_MODE21_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE21_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_MODE21_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_MODE21_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE21_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_MODE21_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE21_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN,
           CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE21_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN,
           CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE21_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN,
           CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_MODE4_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE4_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_MODE4_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE4_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_MODE4_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_MODE4_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE4_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_MODE4_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE4_PG_INC0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE4_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE4_PG_INC0,
           CTL_REGS_RX_MODE4_PG_INC0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE4_PG_INC0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE4_PG_INC0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE4_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE4_PG_INC0,
           CTL_REGS_RX_MODE4_PG_INC0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE4_PG_INC0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE4_PG_INC0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE4_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE4_PG_INC0,
           CTL_REGS_RX_MODE4_PG_INC0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE4_PG_INC0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE4_PG_DEC0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE4_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE4_PG_DEC0,
           CTL_REGS_RX_MODE4_PG_DEC0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE4_PG_DEC0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE4_PG_DEC0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE4_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE4_PG_DEC0,
           CTL_REGS_RX_MODE4_PG_DEC0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE4_PG_DEC0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE4_PG_DEC0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE4_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE4_PG_DEC0,
           CTL_REGS_RX_MODE4_PG_DEC0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE4_PG_DEC0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE4_PG_INC1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE4_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE4_PG_INC1,
           CTL_REGS_RX_MODE4_PG_INC1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE4_PG_INC1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE4_PG_INC1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE4_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE4_PG_INC1,
           CTL_REGS_RX_MODE4_PG_INC1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE4_PG_INC1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE4_PG_INC1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE4_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE4_PG_INC1,
           CTL_REGS_RX_MODE4_PG_INC1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE4_PG_INC1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE4_PG_DEC1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE4_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE4_PG_DEC1,
           CTL_REGS_RX_MODE4_PG_DEC1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE4_PG_DEC1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE4_PG_DEC1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE4_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE4_PG_DEC1,
           CTL_REGS_RX_MODE4_PG_DEC1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE4_PG_DEC1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE4_PG_DEC1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE4_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE4_PG_DEC1,
           CTL_REGS_RX_MODE4_PG_DEC1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE4_PG_DEC1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_SPARE_MODE_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_SPARE_MODE_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_SPARE_MODE_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_SPARE_MODE_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_SPARE_MODE_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_SPARE_MODE_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_SPARE_MODE_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_SPARE_MODE_PG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_SPARE_MODE_PG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_SPARE_MODE_PG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_SPARE_MODE_PG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_SPARE_MODE_PG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_SPARE_MODE_PG_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_SPARE_MODE_PG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_SPARE_MODE_PG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_SPARE_MODE_PG_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_SPARE_MODE_PG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_SPARE_MODE_PG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_SPARE_MODE_PG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_SPARE_MODE_PG_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_SPARE_MODE_PG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_SPARE_MODE_PG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_SPARE_MODE_PG_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_SPARE_MODE_PG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_SPARE_MODE_PG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_SPARE_MODE_PG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_SPARE_MODE_PG_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_SPARE_MODE_PG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_SPARE_MODE_PG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_SPARE_MODE_PG_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_SPARE_MODE_PG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_SPARE_MODE_PG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_SPARE_MODE_PG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_SPARE_MODE_PG_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_SPARE_MODE_PG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_SPARE_MODE_PG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_SPARE_MODE_PG_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_SPARE_MODE_PG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_SPARE_MODE_PG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_SPARE_MODE_PG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_SPARE_MODE_PG_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_SPARE_MODE_PG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_TX_CNTL3_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_CNTL3_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_TX_CNTL3_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_CNTL3_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_TX_CNTL3_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_TX_CNTL3_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL3_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_TX_CNTL3_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL3_PG_FINE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL3_PG_FINE_SEL,
           CTL_REGS_TX_CNTL3_PG_FINE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL3_PG_FINE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL3_PG_FINE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL3_PG_FINE_SEL,
           CTL_REGS_TX_CNTL3_PG_FINE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL3_PG_FINE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_CNTL3_PG_FINE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL3_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_CNTL3_PG_FINE_SEL,
           CTL_REGS_TX_CNTL3_PG_FINE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL3_PG_FINE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL3_PG_COARSE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL3_PG_COARSE_SEL,
           CTL_REGS_TX_CNTL3_PG_COARSE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL3_PG_COARSE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL3_PG_COARSE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL3_PG_COARSE_SEL,
           CTL_REGS_TX_CNTL3_PG_COARSE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL3_PG_COARSE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_CNTL3_PG_COARSE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL3_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_CNTL3_PG_COARSE_SEL,
           CTL_REGS_TX_CNTL3_PG_COARSE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL3_PG_COARSE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL3_PG_BER_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL3_PG_BER_SEL,
           CTL_REGS_TX_CNTL3_PG_BER_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL3_PG_BER_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL3_PG_BER_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL3_PG_BER_SEL,
           CTL_REGS_TX_CNTL3_PG_BER_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL3_PG_BER_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_CNTL3_PG_BER_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL3_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_CNTL3_PG_BER_SEL,
           CTL_REGS_TX_CNTL3_PG_BER_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL3_PG_BER_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNT13_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT13_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNT13_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT13_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNT13_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNT13_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT13_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNT13_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT13_PG_DISABLE_SM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT13_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT13_PG_DISABLE_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT13_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT13_PG_DISABLE_SM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT13_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT13_PG_DISABLE_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT13_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT13_PG_DISABLE_SM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT13_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_CNT13_PG_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT13_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_CNT13_PG_DISABLE_SM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT13_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_CNT13_PG_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT13_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT13_PG_DISABLE_SM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT13_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT13_PG_DISABLE_SM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT13_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_CNT13_PG_DISABLE_SM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT13_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_CNT13_PG_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT13_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT13_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT13_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT13_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT13_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT13_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT13_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT13_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT13_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT13_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT13_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT13_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT13_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNT23_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT23_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNT23_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT23_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNT23_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNT23_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT23_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNT23_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT23_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15,
           DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT23_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15,
           DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT23_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15,
           DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNT33_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT33_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNT33_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT33_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNT33_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNT33_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT33_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNT33_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT33_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1,
           DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT33_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1,
           DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT33_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1,
           DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_SPARE_MODE_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_SPARE_MODE_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_SPARE_MODE_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_SPARE_MODE_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_SPARE_MODE_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_SPARE_MODE_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_SPARE_MODE_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_SPARE_MODE_PG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_SPARE_MODE_PG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_SPARE_MODE_PG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_SPARE_MODE_PG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_SPARE_MODE_PG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_SPARE_MODE_PG_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_SPARE_MODE_PG_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_SPARE_MODE_PG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_SPARE_MODE_PG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_SPARE_MODE_PG_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_SPARE_MODE_PG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_SPARE_MODE_PG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_SPARE_MODE_PG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_SPARE_MODE_PG_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_SPARE_MODE_PG_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_SPARE_MODE_PG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_SPARE_MODE_PG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_SPARE_MODE_PG_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_SPARE_MODE_PG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_SPARE_MODE_PG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_SPARE_MODE_PG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_SPARE_MODE_PG_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_SPARE_MODE_PG_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_SPARE_MODE_PG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_SPARE_MODE_PG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_SPARE_MODE_PG_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_SPARE_MODE_PG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_SPARE_MODE_PG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_SPARE_MODE_PG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_SPARE_MODE_PG_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_SPARE_MODE_PG_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_SPARE_MODE_PG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_SPARE_MODE_PG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_SPARE_MODE_PG_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_SPARE_MODE_PG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_SPARE_MODE_PG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_SPARE_MODE_PG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_SPARE_MODE_PG_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_SPARE_MODE_PG_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_SPARE_MODE_PG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_SPARE_MODE_PG_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_SPARE_MODE_PG_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_SPARE_MODE_PG_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_SPARE_MODE_PG_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_SPARE_MODE_PG_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_SPARE_MODE_PG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_SPARE_MODE_PG_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_SPARE_MODE_PG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_SPARE_MODE_PG_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_SPARE_MODE_PG_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_SPARE_MODE_PG_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_SPARE_MODE_PG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_SPARE_MODE_PG_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_SPARE_MODE_PG_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_SPARE_MODE_PG_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_SPARE_MODE_PG_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_SPARE_MODE_PG_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_SPARE_MODE_PG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_SPARE_MODE_PG_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_SPARE_MODE_PG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_SPARE_MODE_PG_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_SPARE_MODE_PG_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_SPARE_MODE_PG_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_SPARE_MODE_PG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_SPARE_MODE_PG_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_SPARE_MODE_PG_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_SPARE_MODE_PG_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_SPARE_MODE_PG_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_SPARE_MODE_PG_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_SPARE_MODE_PG_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_SPARE_MODE_PG_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_SPARE_MODE_PG_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_SPARE_MODE_PG_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_SPARE_MODE_PG_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_SPARE_MODE_PG_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_SPARE_MODE_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_SPARE_MODE_PG_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_SPARE_MODE_PG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC_OMI_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC_OMI_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_REG_RW;
#endif
    return fapi2::getScom(i_target, MC_OMI_FIR_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC_OMI_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, MC_OMI_FIR_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC_OMI_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC_OMI_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, MC_OMI_FIR_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC_OMI_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, MC_OMI_FIR_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC_OMI_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC_OMI_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, MC_OMI_FIR_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC_OMI_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, MC_OMI_FIR_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_DATA_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_DATA_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_DATA_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_DATA_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_DATA_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_DATA_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_DATA_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_DATA_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_DATA_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_FLIT_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_FLIT_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_FLIT_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_FLIT_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_FLIT_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_FLIT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_FLIT_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_FLIT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_FLIT_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_FLIT_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_FLIT_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_FLIT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_CRC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_CRC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_CRC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_CRC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_CRC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_CRC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_CRC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_CRC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_CRC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_NACK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_NACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_NACK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_NACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_NACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_NACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_NACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_NACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_NACK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_NACK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_NACK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_NACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_X4_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_X4_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_X4_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_X4_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_X4_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_X4_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_X4_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_X4_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_X4_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_X4_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_X4_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_X4_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_EDPL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_EDPL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_EDPL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_EDPL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_EDPL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_EDPL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_EDPL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_EDPL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_EDPL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_EDPL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_EDPL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_EDPL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ERROR_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ERROR_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ERROR_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ERROR_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ERROR_RETRAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ERROR_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_EDPL_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_EDPL_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_EDPL_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_EDPL_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_EDPL_RETRAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_EDPL_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_FATAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_FATAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_FATAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_FATAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_FATAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_FATAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_FATAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_DATA_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_DATA_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_DATA_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_DATA_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_DATA_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_DATA_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_DATA_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_DATA_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_DATA_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_FLIT_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_FLIT_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_FLIT_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_FLIT_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_FLIT_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_FLIT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_FLIT_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_FLIT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_FLIT_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_FLIT_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_FLIT_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_FLIT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_FLIT_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_CRC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_CRC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_CRC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_CRC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_CRC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_CRC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_CRC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_CRC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_CRC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_NACK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_NACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_NACK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_NACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_NACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_NACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_NACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_NACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_NACK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_NACK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_NACK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_NACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_NACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_X4_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_X4_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_X4_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_X4_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_X4_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_X4_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_X4_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_X4_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_X4_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_X4_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_X4_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_X4_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_X4_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_EDPL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_EDPL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_EDPL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_EDPL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_EDPL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_EDPL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_EDPL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_EDPL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_EDPL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_EDPL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_EDPL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_EDPL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_EDPL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ERROR_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ERROR_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ERROR_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ERROR_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ERROR_RETRAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ERROR_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ERROR_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_EDPL_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_EDPL_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_EDPL_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_EDPL_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_EDPL_RETRAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_EDPL_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_EDPL_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_PERF_MON_WRAPPED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_PERF_MON_WRAPPED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_PERF_MON_WRAPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_PERF_MON_WRAPPED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_REG_PERF_MON_WRAPPED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_PERF_MON_WRAPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_REG_PERF_MON_WRAPPED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_REG_PERF_MON_WRAPPED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_PERF_MON_WRAPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_REG_PERF_MON_WRAPPED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_REG_PERF_MON_WRAPPED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_PERF_MON_WRAPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_REG_PERF_MON_WRAPPED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_REG_PERF_MON_WRAPPED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_PERF_MON_WRAPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_REG_PERF_MON_WRAPPED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_REG_RW, MC_OMI_FIR_REG_WO_AND, MC_OMI_FIR_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_REG_PERF_MON_WRAPPED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_REG_PERF_MON_WRAPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX_CTL_SM_REGS_CTLSM_CNTL12_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_CNTL12_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX_CTL_SM_REGS_CTLSM_CNTL12_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_CNTL12_PG;
#endif
    return fapi2::getScom(i_target, TX_CTL_SM_REGS_CTLSM_CNTL12_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX_CTL_SM_REGS_CTLSM_CNTL12_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL12_PG));
#endif
    return fapi2::putScom(i_target, TX_CTL_SM_REGS_CTLSM_CNTL12_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL12_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6,
           TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL12_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6,
           TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL12_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6,
           TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL12_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL12_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL12_PG));
#endif
    return o_data.setBit<TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL12_PG));
#endif
    return o_data.clearBit<TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL12_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL12_PG));
#endif
    return i_data.getBit<TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL12_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME,
           TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL12_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME,
           TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL12_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME,
           TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL12_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL12_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL12_PG));
#endif
    return o_data.setBit<TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL12_PG));
#endif
    return o_data.clearBit<TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL12_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL12_PG));
#endif
    return i_data.getBit<TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX_CTL_SM_REGS_CTLSM_CNTL2_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_CNTL2_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX_CTL_SM_REGS_CTLSM_CNTL2_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_CNTL2_PG;
#endif
    return fapi2::getScom(i_target, TX_CTL_SM_REGS_CTLSM_CNTL2_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX_CTL_SM_REGS_CTLSM_CNTL2_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL2_PG));
#endif
    return fapi2::putScom(i_target, TX_CTL_SM_REGS_CTLSM_CNTL2_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL2_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23,
           TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL2_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23,
           TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL2_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23,
           TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX_CTL_SM_REGS_CTLSM_STAT2_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_STAT2_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX_CTL_SM_REGS_CTLSM_STAT2_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_STAT2_PG;
#endif
    return fapi2::getScom(i_target, TX_CTL_SM_REGS_CTLSM_STAT2_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX_CTL_SM_REGS_CTLSM_STAT2_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_STAT2_PG));
#endif
    return fapi2::putScom(i_target, TX_CTL_SM_REGS_CTLSM_STAT2_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG;
#endif
    return fapi2::getScom(i_target, TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG));
#endif
    return fapi2::putScom(i_target, TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG_TX_PG_FIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG_TX_PG_FIR_ERR_INJ,
           TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG_TX_PG_FIR_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG_TX_PG_FIR_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG_TX_PG_FIR_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG_TX_PG_FIR_ERR_INJ,
           TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG_TX_PG_FIR_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG_TX_PG_FIR_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG_TX_PG_FIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG_TX_PG_FIR_ERR_INJ,
           TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG_TX_PG_FIR_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG_TX_PG_FIR_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}


}
}

#endif
