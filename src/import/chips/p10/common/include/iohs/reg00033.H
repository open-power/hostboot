/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00033.H $         */
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

#ifndef __IOHS_REG00033_H_
#define __IOHS_REG00033_H_

namespace scomt
{
namespace iohs
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_EN,
           IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_EN,
           IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_EN,
           IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_SEL,
           IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_SEL,
           IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_SEL,
           IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL21_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_EN,
           IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_EN,
           IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_EN,
           IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_SEL,
           IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_SEL,
           IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_SEL,
           IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL4_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY,
           IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY,
           IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY,
           IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_RXCAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_RXCAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_RXCAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_RXCAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_RXCAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_RXCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_RXCAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_RXCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_RXCAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_RXCAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_RXCAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_RXCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL,
           IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL,
           IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL,
           IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_PAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_PAT,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_PAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_PAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_PAT,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_PAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_PAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_PAT,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_PAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_AZ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_AZ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_AZ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_AZ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_AZ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_AZ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_AZ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_AZ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_AZ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_AZ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_AZ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_AZ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_AZ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_AZ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_AZ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_AZ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_AZ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL17_PL_DCC_AZ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_EN,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_EN,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_EN,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_SEL,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_SEL,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_SEL,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL27_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_EN,
           IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_EN,
           IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_EN,
           IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_SEL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_SEL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_SEL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL20_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PERF_SEL_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PERF_SEL_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PERF_SEL_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PERF_SEL_CONFIG;
#endif
    return fapi2::getScom(i_target, PERF_SEL_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PERF_SEL_CONFIG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return fapi2::putScom(i_target, PERF_SEL_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PERF_SEL_CONFIG_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return o_data.insertFromRight<PERF_SEL_CONFIG_0,
           PERF_SEL_CONFIG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_SEL_CONFIG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PERF_SEL_CONFIG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return o_data.insertFromRight<PERF_SEL_CONFIG_0,
           PERF_SEL_CONFIG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_SEL_CONFIG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PERF_SEL_CONFIG_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return i_data.extractToRight<PERF_SEL_CONFIG_0,
           PERF_SEL_CONFIG_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_SEL_CONFIG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PERF_SEL_CONFIG_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return o_data.insertFromRight<PERF_SEL_CONFIG_1,
           PERF_SEL_CONFIG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_SEL_CONFIG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PERF_SEL_CONFIG_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return o_data.insertFromRight<PERF_SEL_CONFIG_1,
           PERF_SEL_CONFIG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_SEL_CONFIG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PERF_SEL_CONFIG_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return i_data.extractToRight<PERF_SEL_CONFIG_1,
           PERF_SEL_CONFIG_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_SEL_CONFIG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PERF_SEL_CONFIG_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return o_data.insertFromRight<PERF_SEL_CONFIG_2,
           PERF_SEL_CONFIG_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_SEL_CONFIG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PERF_SEL_CONFIG_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return o_data.insertFromRight<PERF_SEL_CONFIG_2,
           PERF_SEL_CONFIG_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_SEL_CONFIG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PERF_SEL_CONFIG_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return i_data.extractToRight<PERF_SEL_CONFIG_2,
           PERF_SEL_CONFIG_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_SEL_CONFIG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PERF_SEL_CONFIG_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return o_data.insertFromRight<PERF_SEL_CONFIG_3,
           PERF_SEL_CONFIG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_SEL_CONFIG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PERF_SEL_CONFIG_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return o_data.insertFromRight<PERF_SEL_CONFIG_3,
           PERF_SEL_CONFIG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_SEL_CONFIG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PERF_SEL_CONFIG_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return i_data.extractToRight<PERF_SEL_CONFIG_3,
           PERF_SEL_CONFIG_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_SEL_CONFIG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PERF_SEL_CONFIG_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return o_data.insertFromRight<PERF_SEL_CONFIG_4,
           PERF_SEL_CONFIG_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_SEL_CONFIG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PERF_SEL_CONFIG_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return o_data.insertFromRight<PERF_SEL_CONFIG_4,
           PERF_SEL_CONFIG_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_SEL_CONFIG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PERF_SEL_CONFIG_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return i_data.extractToRight<PERF_SEL_CONFIG_4,
           PERF_SEL_CONFIG_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_SEL_CONFIG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PERF_SEL_CONFIG_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return o_data.insertFromRight<PERF_SEL_CONFIG_5,
           PERF_SEL_CONFIG_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_SEL_CONFIG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PERF_SEL_CONFIG_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return o_data.insertFromRight<PERF_SEL_CONFIG_5,
           PERF_SEL_CONFIG_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_SEL_CONFIG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PERF_SEL_CONFIG_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return i_data.extractToRight<PERF_SEL_CONFIG_5,
           PERF_SEL_CONFIG_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_SEL_CONFIG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PERF_SEL_CONFIG_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return o_data.insertFromRight<PERF_SEL_CONFIG_6,
           PERF_SEL_CONFIG_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_SEL_CONFIG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PERF_SEL_CONFIG_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return o_data.insertFromRight<PERF_SEL_CONFIG_6,
           PERF_SEL_CONFIG_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_SEL_CONFIG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PERF_SEL_CONFIG_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return i_data.extractToRight<PERF_SEL_CONFIG_6,
           PERF_SEL_CONFIG_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_SEL_CONFIG_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PERF_SEL_CONFIG_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return o_data.insertFromRight<PERF_SEL_CONFIG_7,
           PERF_SEL_CONFIG_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_SEL_CONFIG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PERF_SEL_CONFIG_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return o_data.insertFromRight<PERF_SEL_CONFIG_7,
           PERF_SEL_CONFIG_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_SEL_CONFIG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PERF_SEL_CONFIG_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PERF_SEL_CONFIG));
#endif
    return i_data.extractToRight<PERF_SEL_CONFIG_7,
           PERF_SEL_CONFIG_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PERF_SEL_CONFIG_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
