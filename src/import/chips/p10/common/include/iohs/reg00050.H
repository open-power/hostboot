/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00050.H $         */
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

#ifndef __IOHS_REG00050_H_
#define __IOHS_REG00050_H_

namespace scomt
{
namespace iohs
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK,
           IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK,
           IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK,
           IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN,
           IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN,
           IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN,
           IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_LAT_MEASURE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = LAT_MEASURE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_LAT_MEASURE(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = LAT_MEASURE;
#endif
    return fapi2::getScom(i_target, LAT_MEASURE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_LAT_MEASURE(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return fapi2::putScom(i_target, LAT_MEASURE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_LINK0_ROUND_TRIP_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.insertFromRight<LAT_MEASURE_LINK0_ROUND_TRIP_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LINK0_ROUND_TRIP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_LINK0_ROUND_TRIP_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.insertFromRight<LAT_MEASURE_LINK0_ROUND_TRIP_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LINK0_ROUND_TRIP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_LINK0_ROUND_TRIP_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.setBit<LAT_MEASURE_LINK0_ROUND_TRIP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LINK0_ROUND_TRIP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_LAT_MEASURE_LINK0_ROUND_TRIP_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.clearBit<LAT_MEASURE_LINK0_ROUND_TRIP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LINK0_ROUND_TRIP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_LAT_MEASURE_LINK0_ROUND_TRIP_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return i_data.extractToRight<LAT_MEASURE_LINK0_ROUND_TRIP_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LINK0_ROUND_TRIP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_LAT_MEASURE_LINK0_ROUND_TRIP_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return i_data.getBit<LAT_MEASURE_LINK0_ROUND_TRIP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LINK0_ROUND_TRIP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_LINK0_ROUND_TRIP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.insertFromRight<LAT_MEASURE_LINK0_ROUND_TRIP,
           LAT_MEASURE_LINK0_ROUND_TRIP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LINK0_ROUND_TRIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_LINK0_ROUND_TRIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.insertFromRight<LAT_MEASURE_LINK0_ROUND_TRIP,
           LAT_MEASURE_LINK0_ROUND_TRIP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LINK0_ROUND_TRIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_LAT_MEASURE_LINK0_ROUND_TRIP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return i_data.extractToRight<LAT_MEASURE_LINK0_ROUND_TRIP,
           LAT_MEASURE_LINK0_ROUND_TRIP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LINK0_ROUND_TRIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_LINK1_ROUND_TRIP_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.insertFromRight<LAT_MEASURE_LINK1_ROUND_TRIP_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LINK1_ROUND_TRIP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_LINK1_ROUND_TRIP_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.insertFromRight<LAT_MEASURE_LINK1_ROUND_TRIP_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LINK1_ROUND_TRIP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_LINK1_ROUND_TRIP_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.setBit<LAT_MEASURE_LINK1_ROUND_TRIP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LINK1_ROUND_TRIP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_LAT_MEASURE_LINK1_ROUND_TRIP_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.clearBit<LAT_MEASURE_LINK1_ROUND_TRIP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LINK1_ROUND_TRIP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_LAT_MEASURE_LINK1_ROUND_TRIP_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return i_data.extractToRight<LAT_MEASURE_LINK1_ROUND_TRIP_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LINK1_ROUND_TRIP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_LAT_MEASURE_LINK1_ROUND_TRIP_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return i_data.getBit<LAT_MEASURE_LINK1_ROUND_TRIP_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LINK1_ROUND_TRIP_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_LINK1_ROUND_TRIP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.insertFromRight<LAT_MEASURE_LINK1_ROUND_TRIP,
           LAT_MEASURE_LINK1_ROUND_TRIP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LINK1_ROUND_TRIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_LINK1_ROUND_TRIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.insertFromRight<LAT_MEASURE_LINK1_ROUND_TRIP,
           LAT_MEASURE_LINK1_ROUND_TRIP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LINK1_ROUND_TRIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_LAT_MEASURE_LINK1_ROUND_TRIP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return i_data.extractToRight<LAT_MEASURE_LINK1_ROUND_TRIP,
           LAT_MEASURE_LINK1_ROUND_TRIP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LINK1_ROUND_TRIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.insertFromRight<LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.insertFromRight<LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.setBit<LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.clearBit<LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return i_data.extractToRight<LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return i_data.getBit<LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.insertFromRight<LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.insertFromRight<LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.setBit<LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.clearBit<LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return i_data.extractToRight<LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return i_data.getBit<LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.insertFromRight<LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE,
           LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.insertFromRight<LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE,
           LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return i_data.extractToRight<LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE,
           LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.insertFromRight<LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.insertFromRight<LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.setBit<LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.clearBit<LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return i_data.extractToRight<LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return i_data.getBit<LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.insertFromRight<LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.insertFromRight<LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.setBit<LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.clearBit<LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return i_data.extractToRight<LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return i_data.getBit<LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.insertFromRight<LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE,
           LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.insertFromRight<LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE,
           LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return i_data.extractToRight<LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE,
           LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_LINK0_TOD_LATENCY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.insertFromRight<LAT_MEASURE_LINK0_TOD_LATENCY,
           LAT_MEASURE_LINK0_TOD_LATENCY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LINK0_TOD_LATENCY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_LINK0_TOD_LATENCY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.insertFromRight<LAT_MEASURE_LINK0_TOD_LATENCY,
           LAT_MEASURE_LINK0_TOD_LATENCY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LINK0_TOD_LATENCY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_LAT_MEASURE_LINK0_TOD_LATENCY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return i_data.extractToRight<LAT_MEASURE_LINK0_TOD_LATENCY,
           LAT_MEASURE_LINK0_TOD_LATENCY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LINK0_TOD_LATENCY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_LINK1_TOD_LATENCY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.insertFromRight<LAT_MEASURE_LINK1_TOD_LATENCY,
           LAT_MEASURE_LINK1_TOD_LATENCY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LINK1_TOD_LATENCY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LAT_MEASURE_LINK1_TOD_LATENCY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return o_data.insertFromRight<LAT_MEASURE_LINK1_TOD_LATENCY,
           LAT_MEASURE_LINK1_TOD_LATENCY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LINK1_TOD_LATENCY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_LAT_MEASURE_LINK1_TOD_LATENCY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LAT_MEASURE));
#endif
    return i_data.extractToRight<LAT_MEASURE_LINK1_TOD_LATENCY,
           LAT_MEASURE_LINK1_TOD_LATENCY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LAT_MEASURE_LINK1_TOD_LATENCY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PERF_COUNTERS_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PERF_COUNTERS_1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PERF_COUNTERS_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PERF_COUNTERS_1;
#endif
    return fapi2::getScom(i_target, PERF_COUNTERS_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PERF_COUNTERS_1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PERF_COUNTERS_1));
#endif
    return fapi2::putScom(i_target, PERF_COUNTERS_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PERF_COUNTERS_1_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_COUNTERS_1));
#endif
    return o_data.insertFromRight<PERF_COUNTERS_1_4,
           PERF_COUNTERS_1_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_COUNTERS_1_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PERF_COUNTERS_1_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_COUNTERS_1));
#endif
    return o_data.insertFromRight<PERF_COUNTERS_1_4,
           PERF_COUNTERS_1_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_COUNTERS_1_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PERF_COUNTERS_1_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_COUNTERS_1));
#endif
    return i_data.extractToRight<PERF_COUNTERS_1_4,
           PERF_COUNTERS_1_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_COUNTERS_1_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PERF_COUNTERS_1_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_COUNTERS_1));
#endif
    return o_data.insertFromRight<PERF_COUNTERS_1_5,
           PERF_COUNTERS_1_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_COUNTERS_1_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PERF_COUNTERS_1_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_COUNTERS_1));
#endif
    return o_data.insertFromRight<PERF_COUNTERS_1_5,
           PERF_COUNTERS_1_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_COUNTERS_1_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PERF_COUNTERS_1_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_COUNTERS_1));
#endif
    return i_data.extractToRight<PERF_COUNTERS_1_5,
           PERF_COUNTERS_1_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_COUNTERS_1_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PERF_COUNTERS_1_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_COUNTERS_1));
#endif
    return o_data.insertFromRight<PERF_COUNTERS_1_6,
           PERF_COUNTERS_1_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_COUNTERS_1_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PERF_COUNTERS_1_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_COUNTERS_1));
#endif
    return o_data.insertFromRight<PERF_COUNTERS_1_6,
           PERF_COUNTERS_1_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_COUNTERS_1_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PERF_COUNTERS_1_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_COUNTERS_1));
#endif
    return i_data.extractToRight<PERF_COUNTERS_1_6,
           PERF_COUNTERS_1_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_COUNTERS_1_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PERF_COUNTERS_1_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_COUNTERS_1));
#endif
    return o_data.insertFromRight<PERF_COUNTERS_1_7,
           PERF_COUNTERS_1_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_COUNTERS_1_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PERF_COUNTERS_1_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_COUNTERS_1));
#endif
    return o_data.insertFromRight<PERF_COUNTERS_1_7,
           PERF_COUNTERS_1_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_COUNTERS_1_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PERF_COUNTERS_1_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_COUNTERS_1));
#endif
    return i_data.extractToRight<PERF_COUNTERS_1_7,
           PERF_COUNTERS_1_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_COUNTERS_1_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PHY_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PHY_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PHY_CONFIG(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PHY_CONFIG;
#endif
    return fapi2::getScom(i_target, PHY_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PHY_CONFIG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return fapi2::putScom(i_target, PHY_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_PHY_TRAIN_A_ADJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_PHY_TRAIN_A_ADJ,
           PHY_CONFIG_PHY_TRAIN_A_ADJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PHY_TRAIN_A_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_PHY_TRAIN_A_ADJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_PHY_TRAIN_A_ADJ,
           PHY_CONFIG_PHY_TRAIN_A_ADJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PHY_TRAIN_A_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PHY_CONFIG_PHY_TRAIN_A_ADJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return i_data.extractToRight<PHY_CONFIG_PHY_TRAIN_A_ADJ,
           PHY_CONFIG_PHY_TRAIN_A_ADJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PHY_TRAIN_A_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_PHY_TRAIN_B_ADJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_PHY_TRAIN_B_ADJ,
           PHY_CONFIG_PHY_TRAIN_B_ADJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PHY_TRAIN_B_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_PHY_TRAIN_B_ADJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_PHY_TRAIN_B_ADJ,
           PHY_CONFIG_PHY_TRAIN_B_ADJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PHY_TRAIN_B_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PHY_CONFIG_PHY_TRAIN_B_ADJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return i_data.extractToRight<PHY_CONFIG_PHY_TRAIN_B_ADJ,
           PHY_CONFIG_PHY_TRAIN_B_ADJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PHY_TRAIN_B_ADJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_PHY_TRAIN_TIME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_PHY_TRAIN_TIME,
           PHY_CONFIG_PHY_TRAIN_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PHY_TRAIN_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_PHY_TRAIN_TIME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_PHY_TRAIN_TIME,
           PHY_CONFIG_PHY_TRAIN_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PHY_TRAIN_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PHY_CONFIG_PHY_TRAIN_TIME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return i_data.extractToRight<PHY_CONFIG_PHY_TRAIN_TIME,
           PHY_CONFIG_PHY_TRAIN_TIME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PHY_TRAIN_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_PHY_TRAIN_A_HYST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_PHY_TRAIN_A_HYST,
           PHY_CONFIG_PHY_TRAIN_A_HYST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PHY_TRAIN_A_HYST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_PHY_TRAIN_A_HYST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_PHY_TRAIN_A_HYST,
           PHY_CONFIG_PHY_TRAIN_A_HYST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PHY_TRAIN_A_HYST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PHY_CONFIG_PHY_TRAIN_A_HYST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return i_data.extractToRight<PHY_CONFIG_PHY_TRAIN_A_HYST,
           PHY_CONFIG_PHY_TRAIN_A_HYST_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PHY_TRAIN_A_HYST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_PHY_TRAIN_B_HYST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_PHY_TRAIN_B_HYST,
           PHY_CONFIG_PHY_TRAIN_B_HYST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PHY_TRAIN_B_HYST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_PHY_TRAIN_B_HYST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_PHY_TRAIN_B_HYST,
           PHY_CONFIG_PHY_TRAIN_B_HYST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PHY_TRAIN_B_HYST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PHY_CONFIG_PHY_TRAIN_B_HYST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return i_data.extractToRight<PHY_CONFIG_PHY_TRAIN_B_HYST,
           PHY_CONFIG_PHY_TRAIN_B_HYST_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PHY_TRAIN_B_HYST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_PRBS_PHASE_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_PRBS_PHASE_SELECT,
           PHY_CONFIG_PRBS_PHASE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PRBS_PHASE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_PRBS_PHASE_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_PRBS_PHASE_SELECT,
           PHY_CONFIG_PRBS_PHASE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PRBS_PHASE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PHY_CONFIG_PRBS_PHASE_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return i_data.extractToRight<PHY_CONFIG_PRBS_PHASE_SELECT,
           PHY_CONFIG_PRBS_PHASE_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PRBS_PHASE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_PRBS_CONFIG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_PRBS_CONFIG,
           PHY_CONFIG_PRBS_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PRBS_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_PRBS_CONFIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_PRBS_CONFIG,
           PHY_CONFIG_PRBS_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PRBS_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PHY_CONFIG_PRBS_CONFIG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return i_data.extractToRight<PHY_CONFIG_PRBS_CONFIG,
           PHY_CONFIG_PRBS_CONFIG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PRBS_CONFIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_PRBS_INVERT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_PRBS_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PRBS_INVERT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_PRBS_INVERT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_PRBS_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PRBS_INVERT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_PRBS_INVERT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.setBit<PHY_CONFIG_PRBS_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PRBS_INVERT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PHY_CONFIG_PRBS_INVERT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.clearBit<PHY_CONFIG_PRBS_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PRBS_INVERT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PHY_CONFIG_PRBS_INVERT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return i_data.extractToRight<PHY_CONFIG_PRBS_INVERT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PRBS_INVERT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PHY_CONFIG_PRBS_INVERT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return i_data.getBit<PHY_CONFIG_PRBS_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PRBS_INVERT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_LINK0_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_LINK0_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_LINK0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_LINK0_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_LINK0_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_LINK0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_LINK0_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.setBit<PHY_CONFIG_LINK0_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_LINK0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PHY_CONFIG_LINK0_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.clearBit<PHY_CONFIG_LINK0_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_LINK0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PHY_CONFIG_LINK0_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return i_data.extractToRight<PHY_CONFIG_LINK0_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_LINK0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PHY_CONFIG_LINK0_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return i_data.getBit<PHY_CONFIG_LINK0_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_LINK0_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_LINK1_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_LINK1_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_LINK1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_LINK1_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_LINK1_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_LINK1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_LINK1_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.setBit<PHY_CONFIG_LINK1_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_LINK1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PHY_CONFIG_LINK1_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.clearBit<PHY_CONFIG_LINK1_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_LINK1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PHY_CONFIG_LINK1_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return i_data.extractToRight<PHY_CONFIG_LINK1_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_LINK1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PHY_CONFIG_LINK1_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return i_data.getBit<PHY_CONFIG_LINK1_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_LINK1_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_PRECODER_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_PRECODER_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PRECODER_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_PRECODER_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_PRECODER_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PRECODER_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_PRECODER_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.setBit<PHY_CONFIG_PRECODER_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PRECODER_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PHY_CONFIG_PRECODER_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.clearBit<PHY_CONFIG_PRECODER_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PRECODER_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PHY_CONFIG_PRECODER_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return i_data.extractToRight<PHY_CONFIG_PRECODER_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PRECODER_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PHY_CONFIG_PRECODER_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return i_data.getBit<PHY_CONFIG_PRECODER_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_PRECODER_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_50G_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_50G_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_50G_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_50G_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_50G_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_50G_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_50G_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.setBit<PHY_CONFIG_50G_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_50G_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PHY_CONFIG_50G_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.clearBit<PHY_CONFIG_50G_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_50G_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PHY_CONFIG_50G_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return i_data.extractToRight<PHY_CONFIG_50G_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_50G_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PHY_CONFIG_50G_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return i_data.getBit<PHY_CONFIG_50G_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_50G_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_DL_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_DL_SELECT,
           PHY_CONFIG_DL_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_DL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PHY_CONFIG_DL_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return o_data.insertFromRight<PHY_CONFIG_DL_SELECT,
           PHY_CONFIG_DL_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_DL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PHY_CONFIG_DL_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PHY_CONFIG));
#endif
    return i_data.extractToRight<PHY_CONFIG_DL_SELECT,
           PHY_CONFIG_DL_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PHY_CONFIG_DL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
