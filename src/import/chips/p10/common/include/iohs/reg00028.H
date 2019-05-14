/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00028.H $         */
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

#ifndef __IOHS_REG00028_H_
#define __IOHS_REG00028_H_

namespace scomt
{
namespace iohs
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_D2_CTRL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_D2_CTRL,
           IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_D2_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_D2_CTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_D2_CTRL,
           IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_D2_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_D2_CTRL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_D2_CTRL,
           IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_D2_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL,
           IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL,
           IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL,
           IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_LINK0_ERROR_STATUS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = LINK0_ERROR_STATUS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_LINK0_ERROR_STATUS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = LINK0_ERROR_STATUS;
#endif
    return fapi2::getScom(i_target, LINK0_ERROR_STATUS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_LINK0_ERROR_STATUS(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return fapi2::putScom(i_target, LINK0_ERROR_STATUS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_LINK0_ERROR_STATUS_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<LINK0_ERROR_STATUS_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LINK0_ERROR_STATUS_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LINK0_ERROR_STATUS_RESET_KEEPER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<LINK0_ERROR_STATUS_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LINK0_ERROR_STATUS_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LINK0_ERROR_STATUS_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<LINK0_ERROR_STATUS_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LINK0_ERROR_STATUS_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_LINK0_ERROR_STATUS_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<LINK0_ERROR_STATUS_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LINK0_ERROR_STATUS_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_LINK0_ERROR_STATUS_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<LINK0_ERROR_STATUS_RESET_KEEPER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LINK0_ERROR_STATUS_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_LINK0_ERROR_STATUS_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<LINK0_ERROR_STATUS_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LINK0_ERROR_STATUS_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LINK0_ERROR_STATUS_ERROR_STATUS_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<LINK0_ERROR_STATUS_ERROR_STATUS_CE,
           LINK0_ERROR_STATUS_ERROR_STATUS_CE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LINK0_ERROR_STATUS_ERROR_STATUS_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LINK0_ERROR_STATUS_ERROR_STATUS_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<LINK0_ERROR_STATUS_ERROR_STATUS_CE,
           LINK0_ERROR_STATUS_ERROR_STATUS_CE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LINK0_ERROR_STATUS_ERROR_STATUS_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_LINK0_ERROR_STATUS_ERROR_STATUS_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<LINK0_ERROR_STATUS_ERROR_STATUS_CE,
           LINK0_ERROR_STATUS_ERROR_STATUS_CE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LINK0_ERROR_STATUS_ERROR_STATUS_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LINK0_ERROR_STATUS_ERROR_STATUS_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<LINK0_ERROR_STATUS_ERROR_STATUS_UE,
           LINK0_ERROR_STATUS_ERROR_STATUS_UE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LINK0_ERROR_STATUS_ERROR_STATUS_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LINK0_ERROR_STATUS_ERROR_STATUS_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<LINK0_ERROR_STATUS_ERROR_STATUS_UE,
           LINK0_ERROR_STATUS_ERROR_STATUS_UE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LINK0_ERROR_STATUS_ERROR_STATUS_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_LINK0_ERROR_STATUS_ERROR_STATUS_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<LINK0_ERROR_STATUS_ERROR_STATUS_UE,
           LINK0_ERROR_STATUS_ERROR_STATUS_UE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LINK0_ERROR_STATUS_ERROR_STATUS_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LINK0_ERROR_STATUS_ERROR_STATUS_OSC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<LINK0_ERROR_STATUS_ERROR_STATUS_OSC,
           LINK0_ERROR_STATUS_ERROR_STATUS_OSC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LINK0_ERROR_STATUS_ERROR_STATUS_OSC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LINK0_ERROR_STATUS_ERROR_STATUS_OSC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<LINK0_ERROR_STATUS_ERROR_STATUS_OSC,
           LINK0_ERROR_STATUS_ERROR_STATUS_OSC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LINK0_ERROR_STATUS_ERROR_STATUS_OSC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_LINK0_ERROR_STATUS_ERROR_STATUS_OSC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<LINK0_ERROR_STATUS_ERROR_STATUS_OSC,
           LINK0_ERROR_STATUS_ERROR_STATUS_OSC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LINK0_ERROR_STATUS_ERROR_STATUS_OSC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LINK0_ERROR_STATUS_ERROR_STATUS_TRAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<LINK0_ERROR_STATUS_ERROR_STATUS_TRAIN,
           LINK0_ERROR_STATUS_ERROR_STATUS_TRAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LINK0_ERROR_STATUS_ERROR_STATUS_TRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LINK0_ERROR_STATUS_ERROR_STATUS_TRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<LINK0_ERROR_STATUS_ERROR_STATUS_TRAIN,
           LINK0_ERROR_STATUS_ERROR_STATUS_TRAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LINK0_ERROR_STATUS_ERROR_STATUS_TRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_LINK0_ERROR_STATUS_ERROR_STATUS_TRAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<LINK0_ERROR_STATUS_ERROR_STATUS_TRAIN,
           LINK0_ERROR_STATUS_ERROR_STATUS_TRAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LINK0_ERROR_STATUS_ERROR_STATUS_TRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LINK0_ERROR_STATUS_ERROR_STATUS_UNRECOV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<LINK0_ERROR_STATUS_ERROR_STATUS_UNRECOV,
           LINK0_ERROR_STATUS_ERROR_STATUS_UNRECOV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LINK0_ERROR_STATUS_ERROR_STATUS_UNRECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LINK0_ERROR_STATUS_ERROR_STATUS_UNRECOV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<LINK0_ERROR_STATUS_ERROR_STATUS_UNRECOV,
           LINK0_ERROR_STATUS_ERROR_STATUS_UNRECOV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LINK0_ERROR_STATUS_ERROR_STATUS_UNRECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_LINK0_ERROR_STATUS_ERROR_STATUS_UNRECOV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<LINK0_ERROR_STATUS_ERROR_STATUS_UNRECOV,
           LINK0_ERROR_STATUS_ERROR_STATUS_UNRECOV_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LINK0_ERROR_STATUS_ERROR_STATUS_UNRECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LINK0_ERROR_STATUS_ERROR_STATUS_INTERNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<LINK0_ERROR_STATUS_ERROR_STATUS_INTERNAL,
           LINK0_ERROR_STATUS_ERROR_STATUS_INTERNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LINK0_ERROR_STATUS_ERROR_STATUS_INTERNAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_LINK0_ERROR_STATUS_ERROR_STATUS_INTERNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<LINK0_ERROR_STATUS_ERROR_STATUS_INTERNAL,
           LINK0_ERROR_STATUS_ERROR_STATUS_INTERNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LINK0_ERROR_STATUS_ERROR_STATUS_INTERNAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_LINK0_ERROR_STATUS_ERROR_STATUS_INTERNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<LINK0_ERROR_STATUS_ERROR_STATUS_INTERNAL,
           LINK0_ERROR_STATUS_ERROR_STATUS_INTERNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access LINK0_ERROR_STATUS_ERROR_STATUS_INTERNAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_PRX0_DLR_APST(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PRX0_DLR_APST;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_PRX0_DLR_APST(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PRX0_DLR_APST;
#endif
    return fapi2::getScom(i_target, REGS_PRX0_DLR_APST, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_PRX0_DLR_APST(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_PRX0_DLR_APST));
#endif
    return fapi2::putScom(i_target, REGS_PRX0_DLR_APST, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}



}
}

#endif
