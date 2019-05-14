/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00044.H $         */
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

#ifndef __IOHS_REG00044_H_
#define __IOHS_REG00044_H_

namespace scomt
{
namespace iohs
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010,
           IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010,
           IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL));
#endif
    return i_data.extractToRight<IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010,
           IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_DATA,
           IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_DATA,
           IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_DATA,
           IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE,
           IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE,
           IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE,
           IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101,
           IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_DATA,
           IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_DATA,
           IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_DATA,
           IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_EDGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_EDGE,
           IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_EDGE,
           IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_EDGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_EDGE,
           IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL16_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_FILTER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_FILTER,
           IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_FILTER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_FILTER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_FILTER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_FILTER,
           IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_FILTER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_FILTER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_FILTER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_FILTER,
           IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_FILTER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_FILTER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_TERM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_TERM,
           IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_TERM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_TERM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_TERM,
           IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_TERM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_TERM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_TERM,
           IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_TERM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_BIT_REGS_MODE3_PL_TERM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_BIT_REGS_STAT5_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_BIT_REGS_STAT5_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_BIT_REGS_STAT5_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_BIT_REGS_STAT5_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_BIT_REGS_STAT5_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_BIT_REGS_STAT5_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_BIT_REGS_STAT5_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_BIT_REGS_STAT5_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000,
           IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT,
           IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT,
           IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT,
           IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_PHASE_STEP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_PHASE_STEP,
           IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_PHASE_STEP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_PHASE_STEP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_PHASE_STEP,
           IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_PHASE_STEP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_PHASE_STEP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_PHASE_STEP,
           IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_MODE4_PL_PHASE_STEP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_RX_BIT_REGS_STAT2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_BIT_REGS_STAT2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_RX_BIT_REGS_STAT2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_BIT_REGS_STAT2_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_RX_BIT_REGS_STAT2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_RX_BIT_REGS_STAT2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_STAT2_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_RX_BIT_REGS_STAT2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK,
           IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK,
           IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK,
           IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001,
           IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL,
           IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL,
           IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL,
           IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A,
           IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A,
           IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A,
           IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B,
           IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B,
           IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B,
           IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH,
           IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH,
           IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH,
           IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_DATA,
           IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_DATA,
           IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_DATA,
           IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_EDGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_EDGE,
           IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_EDGE,
           IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_EDGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_EDGE,
           IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL17_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_DATA,
           IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_DATA,
           IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_DATA,
           IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_EDGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_EDGE,
           IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_EDGE,
           IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_EDGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_EDGE,
           IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL18_PL_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_GAIN,
           IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_GAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_GAIN,
           IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_GAIN,
           IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_GAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_FREQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_FREQ,
           IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_FREQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_FREQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_FREQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_FREQ,
           IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_FREQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_FREQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_FREQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_FREQ,
           IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_FREQ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL3_PL_FREQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIME_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIME_VAL,
           IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIME_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIME_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIME_VAL,
           IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIME_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIME_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIME_VAL,
           IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIME_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_DISABLE_SM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_DISABLE_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_DISABLE_SM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_DISABLE_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_DISABLE_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_DISABLE_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_DISABLE_SM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_DISABLE_SM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_DISABLE_SM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG;
#endif
    return fapi2::getScom(i_target, IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG));
#endif
    return fapi2::putScom(i_target, IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL,
           IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL,
           IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL,
           IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.setBit<IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.clearBit<IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG));
#endif
    return i_data.getBit<IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_EN,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_EN,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_EN,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_SEL,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_SEL,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_SEL,
           IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL6_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_EN,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_EN,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_EN,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_SEL,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_SEL,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_SEL,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL13_PL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
