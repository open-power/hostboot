/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00046.H $         */
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

#ifndef __PROC_REG00046_H_
#define __PROC_REG00046_H_

namespace scomt
{
namespace proc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_IC_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_IC_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_IC_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_IC_BAR;
#endif
    return fapi2::getScom(i_target, INT_CQ_IC_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_IC_BAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return fapi2::putScom(i_target, INT_CQ_IC_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_IC_BAR_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_IC_BAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_IC_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_IC_BAR_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_IC_BAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_IC_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_IC_BAR_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return o_data.setBit<INT_CQ_IC_BAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_IC_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_IC_BAR_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return o_data.clearBit<INT_CQ_IC_BAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_IC_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_IC_BAR_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return i_data.extractToRight<INT_CQ_IC_BAR_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_IC_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_IC_BAR_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return i_data.getBit<INT_CQ_IC_BAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_IC_BAR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_IC_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_IC_BAR_PAGE_SIZE_64K,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_IC_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_IC_BAR_PAGE_SIZE_64K(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_IC_BAR_PAGE_SIZE_64K,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_IC_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_IC_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return o_data.setBit<INT_CQ_IC_BAR_PAGE_SIZE_64K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_IC_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_CQ_IC_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return o_data.clearBit<INT_CQ_IC_BAR_PAGE_SIZE_64K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_IC_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_IC_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return i_data.extractToRight<INT_CQ_IC_BAR_PAGE_SIZE_64K,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_IC_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_CQ_IC_BAR_PAGE_SIZE_64K(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return i_data.getBit<INT_CQ_IC_BAR_PAGE_SIZE_64K>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_IC_BAR_PAGE_SIZE_64K chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_IC_BAR_ADDR_8_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_IC_BAR_ADDR_8_42,
           INT_CQ_IC_BAR_ADDR_8_42_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_IC_BAR_ADDR_8_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_IC_BAR_ADDR_8_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return o_data.insertFromRight<INT_CQ_IC_BAR_ADDR_8_42,
           INT_CQ_IC_BAR_ADDR_8_42_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_IC_BAR_ADDR_8_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_IC_BAR_ADDR_8_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_IC_BAR));
#endif
    return i_data.extractToRight<INT_CQ_IC_BAR_ADDR_8_42,
           INT_CQ_IC_BAR_ADDR_8_42_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_IC_BAR_ADDR_8_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_CQ_PMC_4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_PMC_4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_CQ_PMC_4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_CQ_PMC_4;
#endif
    return fapi2::getScom(i_target, INT_CQ_PMC_4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_CQ_PMC_4(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_CQ_PMC_4));
#endif
    return fapi2::putScom(i_target, INT_CQ_PMC_4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_CQ_PMC_4_INT_CQ_PMC_4_COUNT_0_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_PMC_4));
#endif
    return o_data.insertFromRight<INT_CQ_PMC_4_INT_CQ_PMC_4_COUNT_0_47,
           INT_CQ_PMC_4_INT_CQ_PMC_4_COUNT_0_47_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PMC_4_INT_CQ_PMC_4_COUNT_0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_CQ_PMC_4_INT_CQ_PMC_4_COUNT_0_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_PMC_4));
#endif
    return o_data.insertFromRight<INT_CQ_PMC_4_INT_CQ_PMC_4_COUNT_0_47,
           INT_CQ_PMC_4_INT_CQ_PMC_4_COUNT_0_47_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PMC_4_INT_CQ_PMC_4_COUNT_0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_CQ_PMC_4_INT_CQ_PMC_4_COUNT_0_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_CQ_PMC_4));
#endif
    return i_data.extractToRight<INT_CQ_PMC_4_INT_CQ_PMC_4_COUNT_0_47,
           INT_CQ_PMC_4_INT_CQ_PMC_4_COUNT_0_47_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_CQ_PMC_4_INT_CQ_PMC_4_COUNT_0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_RECOV_ERR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_NXC_REGS_RECOV_ERR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_RECOV_ERR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_NXC_REGS_RECOV_ERR;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_RECOV_ERR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_RECOV_ERR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_RECOV_ERR));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_RECOV_ERR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_RECOV_ERR_INT_PC_NXC_RECOV_ERR_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_RECOV_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_RECOV_ERR_INT_PC_NXC_RECOV_ERR_ERROR,
           INT_PC_NXC_REGS_RECOV_ERR_INT_PC_NXC_RECOV_ERR_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_RECOV_ERR_INT_PC_NXC_RECOV_ERR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_RECOV_ERR_INT_PC_NXC_RECOV_ERR_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_RECOV_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_RECOV_ERR_INT_PC_NXC_RECOV_ERR_ERROR,
           INT_PC_NXC_REGS_RECOV_ERR_INT_PC_NXC_RECOV_ERR_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_RECOV_ERR_INT_PC_NXC_RECOV_ERR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_RECOV_ERR_INT_PC_NXC_RECOV_ERR_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_RECOV_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_RECOV_ERR_INT_PC_NXC_RECOV_ERR_ERROR,
           INT_PC_NXC_REGS_RECOV_ERR_INT_PC_NXC_RECOV_ERR_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_RECOV_ERR_INT_PC_NXC_RECOV_ERR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_WATCH2_DATA0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_NXC_REGS_WATCH2_DATA0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_WATCH2_DATA0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_NXC_REGS_WATCH2_DATA0;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_WATCH2_DATA0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_WATCH2_DATA0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WATCH2_DATA0));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_WATCH2_DATA0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_NXC_REGS_WOF_ERR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_NXC_REGS_WOF_ERR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_NXC_REGS_WOF_ERR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_NXC_REGS_WOF_ERR;
#endif
    return fapi2::getScom(i_target, INT_PC_NXC_REGS_WOF_ERR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_NXC_REGS_WOF_ERR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return fapi2::putScom(i_target, INT_PC_NXC_REGS_WOF_ERR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_RESERVED_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_SCRUB_WB_CREDIT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_SCRUB_WB_CREDIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_SCRUB_WB_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_SCRUB_WB_CREDIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_SCRUB_WB_CREDIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_SCRUB_WB_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_SCRUB_WB_CREDIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_SCRUB_WB_CREDIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_SCRUB_WB_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_SCRUB_WB_CREDIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_SCRUB_WB_CREDIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_SCRUB_WB_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_SCRUB_WB_CREDIT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_SCRUB_WB_CREDIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_SCRUB_WB_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_SCRUB_WB_CREDIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_SCRUB_WB_CREDIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_SCRUB_WB_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_P0_PTAG_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P1_P0_PTAG_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_P0_PTAG_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_P0_PTAG_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P1_P0_PTAG_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_P0_PTAG_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_P0_PTAG_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_P1_P0_PTAG_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_P0_PTAG_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_P1_P0_PTAG_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_P1_P0_PTAG_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_P0_PTAG_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_P1_P0_PTAG_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_P1_P0_PTAG_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_P0_PTAG_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_P1_P0_PTAG_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_P1_P0_PTAG_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_P0_PTAG_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_PTAG_IN_USE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_PTAG_IN_USE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_PTAG_IN_USE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_PTAG_IN_USE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_PTAG_IN_USE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_PTAG_IN_USE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_PTAG_IN_USE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_PTAG_IN_USE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_PTAG_IN_USE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_PTAG_IN_USE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_PTAG_IN_USE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_PTAG_IN_USE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_PTAG_IN_USE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_PTAG_IN_USE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_PTAG_IN_USE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_PTAG_IN_USE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_PTAG_IN_USE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_PTAG_IN_USE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P0_SYNC_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P0_SYNC_OVERFLOW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_SYNC_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P0_SYNC_OVERFLOW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P0_SYNC_OVERFLOW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_SYNC_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P0_SYNC_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_P0_SYNC_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_SYNC_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_P0_SYNC_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_P0_SYNC_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_SYNC_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_P0_SYNC_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_P0_SYNC_OVERFLOW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_SYNC_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_P0_SYNC_OVERFLOW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_P0_SYNC_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_SYNC_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P0_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P0_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P0_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P0_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P0_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_P0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_P0_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_P0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_P0_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_P0_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_P0_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_P0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P0_TAG_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P0_TAG_SRAM_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_TAG_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P0_TAG_SRAM_ECC_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P0_TAG_SRAM_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_TAG_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P0_TAG_SRAM_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_P0_TAG_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_TAG_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_P0_TAG_SRAM_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_P0_TAG_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_TAG_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_P0_TAG_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_P0_TAG_SRAM_ECC_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_TAG_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_P0_TAG_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_P0_TAG_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_TAG_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P0_STATE_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P0_STATE_SRAM_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_STATE_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P0_STATE_SRAM_ECC_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P0_STATE_SRAM_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_STATE_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P0_STATE_SRAM_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_P0_STATE_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_STATE_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_P0_STATE_SRAM_ECC_UE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_P0_STATE_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_STATE_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_P0_STATE_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_P0_STATE_SRAM_ECC_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_STATE_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_P0_STATE_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_P0_STATE_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_STATE_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_8_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_8_9,
           INT_PC_NXC_REGS_WOF_ERR_RESERVED_8_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_8_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_8_9,
           INT_PC_NXC_REGS_WOF_ERR_RESERVED_8_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_8_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_8_9,
           INT_PC_NXC_REGS_WOF_ERR_RESERVED_8_9_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_ATX_WB_CREDIT_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_ATX_WB_CREDIT_OVERFLOW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_ATX_WB_CREDIT_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_ATX_WB_CREDIT_OVERFLOW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_ATX_WB_CREDIT_OVERFLOW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_ATX_WB_CREDIT_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_ATX_WB_CREDIT_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_ATX_WB_CREDIT_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_ATX_WB_CREDIT_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_ATX_WB_CREDIT_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_ATX_WB_CREDIT_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_ATX_WB_CREDIT_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_ATX_WB_CREDIT_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_ATX_WB_CREDIT_OVERFLOW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_ATX_WB_CREDIT_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_ATX_WB_CREDIT_OVERFLOW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_ATX_WB_CREDIT_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_ATX_WB_CREDIT_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_UNLOCK_FIFO_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_UNLOCK_FIFO_OVERFLOW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_UNLOCK_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_UNLOCK_FIFO_OVERFLOW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_UNLOCK_FIFO_OVERFLOW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_UNLOCK_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_UNLOCK_FIFO_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_UNLOCK_FIFO_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_UNLOCK_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_UNLOCK_FIFO_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_UNLOCK_FIFO_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_UNLOCK_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_UNLOCK_FIFO_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_UNLOCK_FIFO_OVERFLOW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_UNLOCK_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_UNLOCK_FIFO_OVERFLOW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_UNLOCK_FIFO_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_UNLOCK_FIFO_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_12_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_12_13,
           INT_PC_NXC_REGS_WOF_ERR_RESERVED_12_13_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_12_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_12_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_12_13,
           INT_PC_NXC_REGS_WOF_ERR_RESERVED_12_13_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_12_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_12_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_12_13,
           INT_PC_NXC_REGS_WOF_ERR_RESERVED_12_13_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_12_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P0_SRAM_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P0_SRAM_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P0_SRAM_ECC_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P0_SRAM_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P0_SRAM_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_P0_SRAM_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_P0_SRAM_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_P0_SRAM_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_P0_SRAM_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_P0_SRAM_ECC_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_P0_SRAM_ECC_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_P0_SRAM_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P0_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_RESERVED_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_RESERVED_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_RESERVED_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_RESERVED_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_RESERVED_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_RESERVED_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_RESERVED_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_RESERVED_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_AIB_CREDIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_AIB_CREDIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_AIB_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_AIB_CREDIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_AIB_CREDIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_AIB_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_AIB_CREDIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_AIB_CREDIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_AIB_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_AIB_CREDIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_AIB_CREDIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_AIB_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_AIB_CREDIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_AIB_CREDIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_AIB_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_AIB_CREDIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_AIB_CREDIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_AIB_CREDIT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_18_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_18_19,
           INT_PC_NXC_REGS_WOF_ERR_RESERVED_18_19_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_18_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_18_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_18_19,
           INT_PC_NXC_REGS_WOF_ERR_RESERVED_18_19_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_18_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_18_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_18_19,
           INT_PC_NXC_REGS_WOF_ERR_RESERVED_18_19_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_18_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_REPLAY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_REPLAY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_REPLAY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_REPLAY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_REPLAY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_REPLAY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_REPLAY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_REPLAY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_REPLAY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_REPLAY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_REPLAY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_REPLAY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_REPLAY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_REPLAY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_REPLAY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_REPLAY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_REPLAY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_REPLAY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P1_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P1_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_P1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_P1_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_P1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_P1_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_P1_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_P1_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_P1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_RESERVED_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_RESERVED_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_RESERVED_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_RESERVED_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_CACHE_IDX_MATCH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_CACHE_IDX_MATCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_CACHE_IDX_MATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_CACHE_IDX_MATCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_CACHE_IDX_MATCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_CACHE_IDX_MATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_CACHE_IDX_MATCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_CACHE_IDX_MATCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_CACHE_IDX_MATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_CACHE_IDX_MATCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_CACHE_IDX_MATCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_CACHE_IDX_MATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_CACHE_IDX_MATCH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_CACHE_IDX_MATCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_CACHE_IDX_MATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_CACHE_IDX_MATCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_CACHE_IDX_MATCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_CACHE_IDX_MATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_DATA_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P1_DATA_SRAM_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_DATA_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_DATA_SRAM_ECC_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P1_DATA_SRAM_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_DATA_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_DATA_SRAM_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_P1_DATA_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_DATA_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_P1_DATA_SRAM_ECC_UE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_P1_DATA_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_DATA_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_P1_DATA_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_P1_DATA_SRAM_ECC_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_DATA_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_P1_DATA_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_P1_DATA_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_DATA_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_PTAG_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P1_PTAG_SRAM_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_PTAG_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_PTAG_SRAM_ECC_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P1_PTAG_SRAM_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_PTAG_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_PTAG_SRAM_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_P1_PTAG_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_PTAG_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_P1_PTAG_SRAM_ECC_UE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_P1_PTAG_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_PTAG_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_P1_PTAG_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_P1_PTAG_SRAM_ECC_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_PTAG_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_P1_PTAG_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_P1_PTAG_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_PTAG_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_ATX_CREDIT_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_ATX_CREDIT_OVERFLOW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_ATX_CREDIT_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_ATX_CREDIT_OVERFLOW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_ATX_CREDIT_OVERFLOW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_ATX_CREDIT_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_ATX_CREDIT_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_ATX_CREDIT_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_ATX_CREDIT_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_ATX_CREDIT_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_ATX_CREDIT_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_ATX_CREDIT_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_ATX_CREDIT_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_ATX_CREDIT_OVERFLOW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_ATX_CREDIT_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_ATX_CREDIT_OVERFLOW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_ATX_CREDIT_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_ATX_CREDIT_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_RESERVED_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_RESERVED_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_RESERVED_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_RESERVED_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_PRIV_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_PRIV_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_PRIV_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_PRIV_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_PRIV_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_PRIV_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_PRIV_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_PRIV_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_PRIV_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_PRIV_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_PRIV_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_PRIV_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_PRIV_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_PRIV_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_PRIV_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_PRIV_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_PRIV_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_CHKOUT_PRIV_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_SRAM_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P1_SRAM_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_SRAM_ECC_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P1_SRAM_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_SRAM_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_P1_SRAM_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_P1_SRAM_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_P1_SRAM_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_P1_SRAM_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_P1_SRAM_ECC_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_P1_SRAM_ECC_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_P1_SRAM_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_PROC_SW_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P1_PROC_SW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_PROC_SW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_PROC_SW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P1_PROC_SW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_PROC_SW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_PROC_SW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_P1_PROC_SW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_PROC_SW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_P1_PROC_SW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_P1_PROC_SW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_PROC_SW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_P1_PROC_SW_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_P1_PROC_SW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_PROC_SW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_P1_PROC_SW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_P1_PROC_SW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_PROC_SW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_PROC_HW_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P1_PROC_HW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_PROC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_PROC_HW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_P1_PROC_HW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_PROC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_P1_PROC_HW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_P1_PROC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_PROC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_P1_PROC_HW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_P1_PROC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_PROC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_P1_PROC_HW_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_P1_PROC_HW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_PROC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_P1_PROC_HW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_P1_PROC_HW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_P1_PROC_HW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_LD_UNDERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_LD_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_LD_UNDERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_LD_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_LD_UNDERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_LD_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_LD_UNDERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_LD_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_LD_UNDERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_LD_UNDERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_LD_UNDERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_LD_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_LD_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_LD_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_LD_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_LD_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_LD_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_LD_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_LD_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_LD_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_LD_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_LD_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_LD_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_LD_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_SRAM_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_LD_CRD_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_LD_CRD_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_CRD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_LD_CRD_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_LD_CRD_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_CRD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_LD_CRD_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_LD_CRD_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_CRD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_LD_CRD_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_LD_CRD_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_CRD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_LD_CRD_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_LD_CRD_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_CRD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_LD_CRD_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_LD_CRD_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_LD_CRD_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_37_52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_37_52,
           INT_PC_NXC_REGS_WOF_ERR_RESERVED_37_52_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_37_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_37_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_37_52,
           INT_PC_NXC_REGS_WOF_ERR_RESERVED_37_52_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_37_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_37_52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_37_52,
           INT_PC_NXC_REGS_WOF_ERR_RESERVED_37_52_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_37_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_REGS_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_REGS_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_REGS_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_REGS_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_REGS_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_REGS_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_REGS_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_REGS_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_REGS_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_REGS_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_REGS_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_REGS_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_REGS_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_REGS_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_REGS_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_REGS_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_REGS_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_REGS_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_WATCH_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_WATCH_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_WATCH_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_WATCH_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_WATCH_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_WATCH_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_WATCH_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_WATCH_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_WATCH_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_WATCH_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_WATCH_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_WATCH_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_WATCH_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_WATCH_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_WATCH_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_WATCH_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_WATCH_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_WATCH_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_NXC_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_NXC_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_NXC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_NXC_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_NXC_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_NXC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_NXC_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_NXC_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_NXC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_NXC_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_NXC_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_NXC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_NXC_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_NXC_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_NXC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_NXC_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_NXC_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_NXC_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_SYNC_POLL_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_SYNC_POLL_OVERFLOW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_SYNC_POLL_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_SYNC_POLL_OVERFLOW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_SYNC_POLL_OVERFLOW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_SYNC_POLL_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_SYNC_POLL_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_SYNC_POLL_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_SYNC_POLL_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_SYNC_POLL_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_SYNC_POLL_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_SYNC_POLL_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_SYNC_POLL_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_SYNC_POLL_OVERFLOW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_SYNC_POLL_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_SYNC_POLL_OVERFLOW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_SYNC_POLL_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_SYNC_POLL_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_OVERFLOW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_OVERFLOW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_OVERFLOW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_OVERFLOW_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_OVERFLOW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_OVERFLOW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_OVERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_OVERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_UNDERFLOW_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_UNDERFLOW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_UNDERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_UNDERFLOW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_UNDERFLOW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_UNDERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_UNDERFLOW_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_UNDERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_UNDERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_UNDERFLOW_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_UNDERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_UNDERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_UNDERFLOW_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_UNDERFLOW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_UNDERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_UNDERFLOW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_UNDERFLOW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_FLUSH_POLL_UNDERFLOW_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_59_60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_59_60,
           INT_PC_NXC_REGS_WOF_ERR_RESERVED_59_60_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_59_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_59_60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_59_60,
           INT_PC_NXC_REGS_WOF_ERR_RESERVED_59_60_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_59_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_RESERVED_59_60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_RESERVED_59_60,
           INT_PC_NXC_REGS_WOF_ERR_RESERVED_59_60_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_RESERVED_59_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_WATCH_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_WATCH_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_WATCH_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_WATCH_PROTOCOL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_WATCH_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_WATCH_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_WATCH_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_WATCH_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_WATCH_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_WATCH_PROTOCOL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_WATCH_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_WATCH_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_WATCH_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_WATCH_PROTOCOL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_WATCH_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_WATCH_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_WATCH_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_WATCH_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.insertFromRight<INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.setBit<INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return o_data.clearBit<INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.extractToRight<INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_NXC_REGS_WOF_ERR));
#endif
    return i_data.getBit<INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_NXC_REGS_WOF_ERR_WATCH_DATA_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_AT_KILL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_REGS_AT_KILL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_AT_KILL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_REGS_AT_KILL;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_AT_KILL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_AT_KILL(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_AT_KILL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AT_KILL_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AT_KILL_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AT_KILL_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AT_KILL_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AT_KILL_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL));
#endif
    return o_data.setBit<INT_PC_REGS_AT_KILL_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_AT_KILL_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL));
#endif
    return o_data.clearBit<INT_PC_REGS_AT_KILL_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AT_KILL_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL));
#endif
    return i_data.extractToRight<INT_PC_REGS_AT_KILL_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_AT_KILL_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL));
#endif
    return i_data.getBit<INT_PC_REGS_AT_KILL_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AT_KILL_VSD_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AT_KILL_VSD_TYPE,
           INT_PC_REGS_AT_KILL_VSD_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_VSD_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AT_KILL_VSD_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AT_KILL_VSD_TYPE,
           INT_PC_REGS_AT_KILL_VSD_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_VSD_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AT_KILL_VSD_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL));
#endif
    return i_data.extractToRight<INT_PC_REGS_AT_KILL_VSD_TYPE,
           INT_PC_REGS_AT_KILL_VSD_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_VSD_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AT_KILL_BLOCKID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AT_KILL_BLOCKID,
           INT_PC_REGS_AT_KILL_BLOCKID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_BLOCKID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AT_KILL_BLOCKID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AT_KILL_BLOCKID,
           INT_PC_REGS_AT_KILL_BLOCKID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_BLOCKID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AT_KILL_BLOCKID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL));
#endif
    return i_data.extractToRight<INT_PC_REGS_AT_KILL_BLOCKID,
           INT_PC_REGS_AT_KILL_BLOCKID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_BLOCKID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AT_KILL_OFFSET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AT_KILL_OFFSET,
           INT_PC_REGS_AT_KILL_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AT_KILL_OFFSET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AT_KILL_OFFSET,
           INT_PC_REGS_AT_KILL_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AT_KILL_OFFSET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL));
#endif
    return i_data.extractToRight<INT_PC_REGS_AT_KILL_OFFSET,
           INT_PC_REGS_AT_KILL_OFFSET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AT_KILL_RESERVED_61_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AT_KILL_RESERVED_61_63,
           INT_PC_REGS_AT_KILL_RESERVED_61_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_RESERVED_61_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AT_KILL_RESERVED_61_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AT_KILL_RESERVED_61_63,
           INT_PC_REGS_AT_KILL_RESERVED_61_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_RESERVED_61_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AT_KILL_RESERVED_61_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL));
#endif
    return i_data.extractToRight<INT_PC_REGS_AT_KILL_RESERVED_61_63,
           INT_PC_REGS_AT_KILL_RESERVED_61_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_RESERVED_61_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_AT_KILL_MASK(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_REGS_AT_KILL_MASK;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_AT_KILL_MASK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_REGS_AT_KILL_MASK;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_AT_KILL_MASK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_AT_KILL_MASK(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL_MASK));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_AT_KILL_MASK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AT_KILL_MASK_VSD_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL_MASK));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AT_KILL_MASK_VSD_TYPE,
           INT_PC_REGS_AT_KILL_MASK_VSD_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_MASK_VSD_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AT_KILL_MASK_VSD_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL_MASK));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AT_KILL_MASK_VSD_TYPE,
           INT_PC_REGS_AT_KILL_MASK_VSD_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_MASK_VSD_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AT_KILL_MASK_VSD_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL_MASK));
#endif
    return i_data.extractToRight<INT_PC_REGS_AT_KILL_MASK_VSD_TYPE,
           INT_PC_REGS_AT_KILL_MASK_VSD_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_MASK_VSD_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AT_KILL_MASK_BLOCKID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL_MASK));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AT_KILL_MASK_BLOCKID,
           INT_PC_REGS_AT_KILL_MASK_BLOCKID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_MASK_BLOCKID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AT_KILL_MASK_BLOCKID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL_MASK));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AT_KILL_MASK_BLOCKID,
           INT_PC_REGS_AT_KILL_MASK_BLOCKID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_MASK_BLOCKID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AT_KILL_MASK_BLOCKID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL_MASK));
#endif
    return i_data.extractToRight<INT_PC_REGS_AT_KILL_MASK_BLOCKID,
           INT_PC_REGS_AT_KILL_MASK_BLOCKID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_MASK_BLOCKID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AT_KILL_MASK_OFFSET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL_MASK));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AT_KILL_MASK_OFFSET,
           INT_PC_REGS_AT_KILL_MASK_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_MASK_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AT_KILL_MASK_OFFSET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL_MASK));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AT_KILL_MASK_OFFSET,
           INT_PC_REGS_AT_KILL_MASK_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_MASK_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AT_KILL_MASK_OFFSET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL_MASK));
#endif
    return i_data.extractToRight<INT_PC_REGS_AT_KILL_MASK_OFFSET,
           INT_PC_REGS_AT_KILL_MASK_OFFSET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_MASK_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AT_KILL_MASK_RESERVED_61_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL_MASK));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AT_KILL_MASK_RESERVED_61_63,
           INT_PC_REGS_AT_KILL_MASK_RESERVED_61_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_MASK_RESERVED_61_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_AT_KILL_MASK_RESERVED_61_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL_MASK));
#endif
    return o_data.insertFromRight<INT_PC_REGS_AT_KILL_MASK_RESERVED_61_63,
           INT_PC_REGS_AT_KILL_MASK_RESERVED_61_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_MASK_RESERVED_61_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_AT_KILL_MASK_RESERVED_61_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_AT_KILL_MASK));
#endif
    return i_data.extractToRight<INT_PC_REGS_AT_KILL_MASK_RESERVED_61_63,
           INT_PC_REGS_AT_KILL_MASK_RESERVED_61_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_AT_KILL_MASK_RESERVED_61_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_DBG_ECC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_REGS_DBG_ECC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_DBG_ECC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_REGS_DBG_ECC;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_DBG_ECC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_DBG_ECC(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_DBG_ECC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_CRESP_ECC_CORR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_CRESP_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_CRESP_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_CRESP_ECC_CORR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_CRESP_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_CRESP_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_CRESP_ECC_CORR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_DIS_CRESP_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_CRESP_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_DIS_CRESP_ECC_CORR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_DIS_CRESP_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_CRESP_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_DIS_CRESP_ECC_CORR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_DIS_CRESP_ECC_CORR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_CRESP_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_DIS_CRESP_ECC_CORR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_DIS_CRESP_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_CRESP_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_ARX_DAT_ECC_CORR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_ARX_DAT_ECC_CORR,
           INT_PC_REGS_DBG_ECC_DIS_ARX_DAT_ECC_CORR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ARX_DAT_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_ARX_DAT_ECC_CORR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_ARX_DAT_ECC_CORR,
           INT_PC_REGS_DBG_ECC_DIS_ARX_DAT_ECC_CORR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ARX_DAT_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_DIS_ARX_DAT_ECC_CORR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_DIS_ARX_DAT_ECC_CORR,
           INT_PC_REGS_DBG_ECC_DIS_ARX_DAT_ECC_CORR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ARX_DAT_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_ARX_TAG_ECC_CORR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_ARX_TAG_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ARX_TAG_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_ARX_TAG_ECC_CORR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_ARX_TAG_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ARX_TAG_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_ARX_TAG_ECC_CORR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_DIS_ARX_TAG_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ARX_TAG_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_DIS_ARX_TAG_ECC_CORR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_DIS_ARX_TAG_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ARX_TAG_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_DIS_ARX_TAG_ECC_CORR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_DIS_ARX_TAG_ECC_CORR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ARX_TAG_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_DIS_ARX_TAG_ECC_CORR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_DIS_ARX_TAG_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ARX_TAG_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_MMIO_LDST_ECC_CORR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_MMIO_LDST_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_MMIO_LDST_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_MMIO_LDST_ECC_CORR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_MMIO_LDST_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_MMIO_LDST_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_MMIO_LDST_ECC_CORR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_DIS_MMIO_LDST_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_MMIO_LDST_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_DIS_MMIO_LDST_ECC_CORR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_DIS_MMIO_LDST_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_MMIO_LDST_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_DIS_MMIO_LDST_ECC_CORR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_DIS_MMIO_LDST_ECC_CORR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_MMIO_LDST_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_DIS_MMIO_LDST_ECC_CORR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_DIS_MMIO_LDST_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_MMIO_LDST_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_MMIO_RSP_ECC_CORR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_MMIO_RSP_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_MMIO_RSP_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_MMIO_RSP_ECC_CORR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_MMIO_RSP_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_MMIO_RSP_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_MMIO_RSP_ECC_CORR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_DIS_MMIO_RSP_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_MMIO_RSP_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_DIS_MMIO_RSP_ECC_CORR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_DIS_MMIO_RSP_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_MMIO_RSP_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_DIS_MMIO_RSP_ECC_CORR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_DIS_MMIO_RSP_ECC_CORR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_MMIO_RSP_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_DIS_MMIO_RSP_ECC_CORR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_DIS_MMIO_RSP_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_MMIO_RSP_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_NRQ_LCL_QUEUE_ECC_CORR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_NRQ_LCL_QUEUE_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_NRQ_LCL_QUEUE_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_NRQ_LCL_QUEUE_ECC_CORR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_NRQ_LCL_QUEUE_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_NRQ_LCL_QUEUE_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_NRQ_LCL_QUEUE_ECC_CORR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_DIS_NRQ_LCL_QUEUE_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_NRQ_LCL_QUEUE_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_DIS_NRQ_LCL_QUEUE_ECC_CORR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_DIS_NRQ_LCL_QUEUE_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_NRQ_LCL_QUEUE_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_DIS_NRQ_LCL_QUEUE_ECC_CORR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_DIS_NRQ_LCL_QUEUE_ECC_CORR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_NRQ_LCL_QUEUE_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_DIS_NRQ_LCL_QUEUE_ECC_CORR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_DIS_NRQ_LCL_QUEUE_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_NRQ_LCL_QUEUE_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_AVX_ECC_CORR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_AVX_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_AVX_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_AVX_ECC_CORR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_AVX_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_AVX_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_AVX_ECC_CORR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_DIS_AVX_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_AVX_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_DIS_AVX_ECC_CORR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_DIS_AVX_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_AVX_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_DIS_AVX_ECC_CORR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_DIS_AVX_ECC_CORR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_AVX_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_DIS_AVX_ECC_CORR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_DIS_AVX_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_AVX_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_ST_ECC_CORR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_ST_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_ST_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_ST_ECC_CORR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_ST_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_ST_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_ST_ECC_CORR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_ST_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_ST_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_ST_ECC_CORR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_ST_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_ST_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_ST_ECC_CORR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_ST_ECC_CORR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_ST_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_ST_ECC_CORR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_ST_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_ST_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_ATX_BAR_ECC_CORR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_ATX_BAR_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_BAR_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_ATX_BAR_ECC_CORR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_ATX_BAR_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_BAR_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_ATX_BAR_ECC_CORR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_DIS_ATX_BAR_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_BAR_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_DIS_ATX_BAR_ECC_CORR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_DIS_ATX_BAR_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_BAR_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_DIS_ATX_BAR_ECC_CORR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_DIS_ATX_BAR_ECC_CORR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_BAR_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_DIS_ATX_BAR_ECC_CORR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_DIS_ATX_BAR_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_BAR_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_ATX_AT_ECC_CORR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_ATX_AT_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_AT_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_ATX_AT_ECC_CORR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_ATX_AT_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_AT_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_ATX_AT_ECC_CORR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_DIS_ATX_AT_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_AT_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_DIS_ATX_AT_ECC_CORR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_DIS_ATX_AT_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_AT_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_DIS_ATX_AT_ECC_CORR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_DIS_ATX_AT_ECC_CORR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_AT_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_DIS_ATX_AT_ECC_CORR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_DIS_ATX_AT_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_AT_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_MMIO_PEND_ECC_CORR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_MMIO_PEND_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_MMIO_PEND_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_MMIO_PEND_ECC_CORR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_MMIO_PEND_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_MMIO_PEND_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_MMIO_PEND_ECC_CORR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_DIS_MMIO_PEND_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_MMIO_PEND_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_DIS_MMIO_PEND_ECC_CORR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_DIS_MMIO_PEND_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_MMIO_PEND_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_DIS_MMIO_PEND_ECC_CORR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_DIS_MMIO_PEND_ECC_CORR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_MMIO_PEND_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_DIS_MMIO_PEND_ECC_CORR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_DIS_MMIO_PEND_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_MMIO_PEND_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_LD_ECC_CORR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_LD_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_LD_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_LD_ECC_CORR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_LD_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_LD_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_LD_ECC_CORR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_LD_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_LD_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_LD_ECC_CORR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_LD_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_LD_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_LD_ECC_CORR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_LD_ECC_CORR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_LD_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_LD_ECC_CORR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_LD_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_TCTXT_LD_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_NRQ_RMT_QUEUE_ECC_CORR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_NRQ_RMT_QUEUE_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_NRQ_RMT_QUEUE_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_NRQ_RMT_QUEUE_ECC_CORR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_NRQ_RMT_QUEUE_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_NRQ_RMT_QUEUE_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_NRQ_RMT_QUEUE_ECC_CORR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_DIS_NRQ_RMT_QUEUE_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_NRQ_RMT_QUEUE_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_DIS_NRQ_RMT_QUEUE_ECC_CORR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_DIS_NRQ_RMT_QUEUE_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_NRQ_RMT_QUEUE_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_DIS_NRQ_RMT_QUEUE_ECC_CORR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_DIS_NRQ_RMT_QUEUE_ECC_CORR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_NRQ_RMT_QUEUE_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_DIS_NRQ_RMT_QUEUE_ECC_CORR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_DIS_NRQ_RMT_QUEUE_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_NRQ_RMT_QUEUE_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_ATX_CTAG_ECC_CORR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_ATX_CTAG_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_CTAG_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_ATX_CTAG_ECC_CORR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_DIS_ATX_CTAG_ECC_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_CTAG_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_DIS_ATX_CTAG_ECC_CORR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_DIS_ATX_CTAG_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_CTAG_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_DIS_ATX_CTAG_ECC_CORR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_DIS_ATX_CTAG_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_CTAG_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_DIS_ATX_CTAG_ECC_CORR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_DIS_ATX_CTAG_ECC_CORR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_CTAG_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_DIS_ATX_CTAG_ECC_CORR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_DIS_ATX_CTAG_ECC_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_DIS_ATX_CTAG_ECC_CORR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_RESERVED_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_RESERVED_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_RESERVED_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_RESERVED_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_RESERVED_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_RESERVED_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_RESERVED_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_RESERVED_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_RESERVED_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_RESERVED_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_RESERVED_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_RESERVED_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_RESERVED_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_RESERVED_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_RESERVED_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_RESERVED_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_RESERVED_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_RESERVED_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_FORCE_SINGLE_BIT_ECC_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_FORCE_SINGLE_BIT_ECC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_FORCE_SINGLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_FORCE_SINGLE_BIT_ECC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_FORCE_SINGLE_BIT_ECC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_FORCE_SINGLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_FORCE_SINGLE_BIT_ECC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_FORCE_SINGLE_BIT_ECC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_FORCE_SINGLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_FORCE_SINGLE_BIT_ECC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_FORCE_SINGLE_BIT_ECC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_FORCE_SINGLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_FORCE_SINGLE_BIT_ECC_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_FORCE_SINGLE_BIT_ECC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_FORCE_SINGLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_FORCE_SINGLE_BIT_ECC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_FORCE_SINGLE_BIT_ECC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_FORCE_SINGLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_FORCE_DOUBLE_BIT_ECC_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_FORCE_DOUBLE_BIT_ECC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_FORCE_DOUBLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_FORCE_DOUBLE_BIT_ECC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_FORCE_DOUBLE_BIT_ECC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_FORCE_DOUBLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_FORCE_DOUBLE_BIT_ECC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_FORCE_DOUBLE_BIT_ECC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_FORCE_DOUBLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_FORCE_DOUBLE_BIT_ECC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_FORCE_DOUBLE_BIT_ECC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_FORCE_DOUBLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_FORCE_DOUBLE_BIT_ECC_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_FORCE_DOUBLE_BIT_ECC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_FORCE_DOUBLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_FORCE_DOUBLE_BIT_ECC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_FORCE_DOUBLE_BIT_ECC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_FORCE_DOUBLE_BIT_ECC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_RESERVED_18_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_RESERVED_18_19,
           INT_PC_REGS_DBG_ECC_RESERVED_18_19_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_RESERVED_18_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_RESERVED_18_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_RESERVED_18_19,
           INT_PC_REGS_DBG_ECC_RESERVED_18_19_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_RESERVED_18_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_RESERVED_18_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_RESERVED_18_19,
           INT_PC_REGS_DBG_ECC_RESERVED_18_19_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_RESERVED_18_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ARX_TAG_SRAM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_ARX_TAG_SRAM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ARX_TAG_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ARX_TAG_SRAM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_ARX_TAG_SRAM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ARX_TAG_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ARX_TAG_SRAM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_ARY_SELECT_ARX_TAG_SRAM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ARX_TAG_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_ARY_SELECT_ARX_TAG_SRAM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_ARY_SELECT_ARX_TAG_SRAM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ARX_TAG_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ARX_TAG_SRAM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_ARX_TAG_SRAM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ARX_TAG_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ARX_TAG_SRAM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_ARY_SELECT_ARX_TAG_SRAM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ARX_TAG_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CRESP_SRAM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_CRESP_SRAM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CRESP_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CRESP_SRAM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_CRESP_SRAM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CRESP_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CRESP_SRAM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_ARY_SELECT_CRESP_SRAM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CRESP_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_ARY_SELECT_CRESP_SRAM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_ARY_SELECT_CRESP_SRAM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CRESP_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CRESP_SRAM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_CRESP_SRAM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CRESP_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CRESP_SRAM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_ARY_SELECT_CRESP_SRAM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CRESP_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_RSP_SRAM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_RSP_SRAM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_RSP_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_RSP_SRAM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_RSP_SRAM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_RSP_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_RSP_SRAM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_RSP_SRAM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_RSP_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_RSP_SRAM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_RSP_SRAM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_RSP_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_RSP_SRAM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_RSP_SRAM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_RSP_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_RSP_SRAM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_RSP_SRAM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_RSP_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_LCL_SRAM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_LCL_SRAM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_LCL_SRAM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_LCL_SRAM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_LCL_SRAM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_LCL_SRAM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_LCL_SRAM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_LCL_SRAM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_LCL_SRAM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_LCL_SRAM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_LCL_SRAM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_LCL_SRAM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_LCL_SRAM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_LCL_SRAM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_LCL_SRAM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_LCL_SRAM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_LCL_SRAM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_LCL_SRAM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_ST_SSA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_ST_SSA,
           INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_ST_SSA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_ST_SSA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_ST_SSA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_ST_SSA,
           INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_ST_SSA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_ST_SSA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_ST_SSA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_ST_SSA,
           INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_ST_SSA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_ST_SSA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_NXC_SSA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_NXC_SSA,
           INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_NXC_SSA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_NXC_SSA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_NXC_SSA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_NXC_SSA,
           INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_NXC_SSA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_NXC_SSA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_NXC_SSA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_NXC_SSA,
           INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_NXC_SSA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_NXC_SSA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_BAR_SRAM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_BAR_SRAM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_BAR_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_BAR_SRAM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_BAR_SRAM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_BAR_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_BAR_SRAM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_BAR_SRAM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_BAR_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_BAR_SRAM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_BAR_SRAM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_BAR_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_BAR_SRAM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_BAR_SRAM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_BAR_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_BAR_SRAM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_BAR_SRAM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_BAR_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AT_SSA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AT_SSA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AT_SSA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AT_SSA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AT_SSA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AT_SSA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AT_SSA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AT_SSA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AT_SSA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AT_SSA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AT_SSA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AT_SSA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AT_SSA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AT_SSA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AT_SSA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AT_SSA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AT_SSA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AT_SSA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AIB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AIB,
           INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AIB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AIB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AIB,
           INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AIB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AIB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AIB,
           INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AIB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_AIB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_PEND_SRAM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_PEND_SRAM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_PEND_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_PEND_SRAM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_PEND_SRAM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_PEND_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_PEND_SRAM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_PEND_SRAM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_PEND_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_PEND_SRAM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_PEND_SRAM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_PEND_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_PEND_SRAM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_PEND_SRAM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_PEND_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_PEND_SRAM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_PEND_SRAM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_PEND_SRAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_LD_SSA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_LD_SSA,
           INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_LD_SSA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_LD_SSA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_LD_SSA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_LD_SSA,
           INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_LD_SSA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_LD_SSA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_LD_SSA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_LD_SSA,
           INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_LD_SSA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_TCTXT_LD_SSA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_RMT_SRAM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_RMT_SRAM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_RMT_SRAM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_RMT_SRAM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_RMT_SRAM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_RMT_SRAM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_RMT_SRAM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_RMT_SRAM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_RMT_SRAM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_RMT_SRAM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_RMT_SRAM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_RMT_SRAM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_RMT_SRAM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_RMT_SRAM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_RMT_SRAM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_RMT_SRAM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_RMT_SRAM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_CMD_NRQ_RMT_SRAM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_CTAG_SSA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_CTAG_SSA,
           INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_CTAG_SSA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_CTAG_SSA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_CTAG_SSA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_CTAG_SSA,
           INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_CTAG_SSA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_CTAG_SSA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_CTAG_SSA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_CTAG_SSA,
           INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_CTAG_SSA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ARY_SELECT_ATX_CTAG_SSA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ATX_AIB_REQ_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ATX_AIB_REQ_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ATX_AIB_REQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ATX_AIB_REQ_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ATX_AIB_REQ_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ATX_AIB_REQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ATX_AIB_REQ_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_ATX_AIB_REQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ATX_AIB_REQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_ATX_AIB_REQ_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_ATX_AIB_REQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ATX_AIB_REQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_ATX_AIB_REQ_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_ATX_AIB_REQ_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ATX_AIB_REQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_ATX_AIB_REQ_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_ATX_AIB_REQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ATX_AIB_REQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ATX_AIB_ARB_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ATX_AIB_ARB_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ATX_AIB_ARB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ATX_AIB_ARB_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_ECC_ATX_AIB_ARB_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ATX_AIB_ARB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_ECC_ATX_AIB_ARB_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.setBit<INT_PC_REGS_DBG_ECC_ATX_AIB_ARB_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ATX_AIB_ARB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_PC_REGS_DBG_ECC_ATX_AIB_ARB_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return o_data.clearBit<INT_PC_REGS_DBG_ECC_ATX_AIB_ARB_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ATX_AIB_ARB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_ECC_ATX_AIB_ARB_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_ECC_ATX_AIB_ARB_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ATX_AIB_ARB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_PC_REGS_DBG_ECC_ATX_AIB_ARB_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_ECC));
#endif
    return i_data.getBit<INT_PC_REGS_DBG_ECC_ATX_AIB_ARB_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_ECC_ATX_AIB_ARB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_DBG_TMOT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_REGS_DBG_TMOT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_DBG_TMOT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_REGS_DBG_TMOT;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_DBG_TMOT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_DBG_TMOT(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_TMOT));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_DBG_TMOT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_TMOT_RESERVED_0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_TMOT));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_TMOT_RESERVED_0_1,
           INT_PC_REGS_DBG_TMOT_RESERVED_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_TMOT_RESERVED_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_TMOT_RESERVED_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_TMOT));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_TMOT_RESERVED_0_1,
           INT_PC_REGS_DBG_TMOT_RESERVED_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_TMOT_RESERVED_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_TMOT_RESERVED_0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_TMOT));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_TMOT_RESERVED_0_1,
           INT_PC_REGS_DBG_TMOT_RESERVED_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_TMOT_RESERVED_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_TMOT_ARX_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_TMOT));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_TMOT_ARX_TIMEOUT,
           INT_PC_REGS_DBG_TMOT_ARX_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_TMOT_ARX_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_TMOT_ARX_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_TMOT));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_TMOT_ARX_TIMEOUT,
           INT_PC_REGS_DBG_TMOT_ARX_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_TMOT_ARX_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_TMOT_ARX_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_TMOT));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_TMOT_ARX_TIMEOUT,
           INT_PC_REGS_DBG_TMOT_ARX_TIMEOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_TMOT_ARX_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_TMOT_RESERVED_8_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_TMOT));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_TMOT_RESERVED_8_9,
           INT_PC_REGS_DBG_TMOT_RESERVED_8_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_TMOT_RESERVED_8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_TMOT_RESERVED_8_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_TMOT));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_TMOT_RESERVED_8_9,
           INT_PC_REGS_DBG_TMOT_RESERVED_8_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_TMOT_RESERVED_8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_TMOT_RESERVED_8_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_TMOT));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_TMOT_RESERVED_8_9,
           INT_PC_REGS_DBG_TMOT_RESERVED_8_9_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_TMOT_RESERVED_8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_TMOT_MMIO_LDST_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_TMOT));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_TMOT_MMIO_LDST_TIMEOUT,
           INT_PC_REGS_DBG_TMOT_MMIO_LDST_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_TMOT_MMIO_LDST_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_PC_REGS_DBG_TMOT_MMIO_LDST_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_TMOT));
#endif
    return o_data.insertFromRight<INT_PC_REGS_DBG_TMOT_MMIO_LDST_TIMEOUT,
           INT_PC_REGS_DBG_TMOT_MMIO_LDST_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_TMOT_MMIO_LDST_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_PC_REGS_DBG_TMOT_MMIO_LDST_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_DBG_TMOT));
#endif
    return i_data.extractToRight<INT_PC_REGS_DBG_TMOT_MMIO_LDST_TIMEOUT,
           INT_PC_REGS_DBG_TMOT_MMIO_LDST_TIMEOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_PC_REGS_DBG_TMOT_MMIO_LDST_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_PC_REGS_TCTXT_LSI_SET_00(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_REGS_TCTXT_LSI_SET_00;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_PC_REGS_TCTXT_LSI_SET_00(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_PC_REGS_TCTXT_LSI_SET_00;
#endif
    return fapi2::getScom(i_target, INT_PC_REGS_TCTXT_LSI_SET_00, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_PC_REGS_TCTXT_LSI_SET_00(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_PC_REGS_TCTXT_LSI_SET_00));
#endif
    return fapi2::putScom(i_target, INT_PC_REGS_TCTXT_LSI_SET_00, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_AIB_TX_CMD_PRIORITY(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_AIB_TX_CMD_PRIORITY;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_AIB_TX_CMD_PRIORITY(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_AIB_TX_CMD_PRIORITY;
#endif
    return fapi2::getScom(i_target, INT_VC_AIB_TX_CMD_PRIORITY, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_AIB_TX_CMD_PRIORITY(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return fapi2::putScom(i_target, INT_VC_AIB_TX_CMD_PRIORITY, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_AIB_TX_CMD_PRIORITY_RESERVED_32_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return o_data.insertFromRight<INT_VC_AIB_TX_CMD_PRIORITY_RESERVED_32_43,
           INT_VC_AIB_TX_CMD_PRIORITY_RESERVED_32_43_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_RESERVED_32_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_AIB_TX_CMD_PRIORITY_RESERVED_32_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return o_data.insertFromRight<INT_VC_AIB_TX_CMD_PRIORITY_RESERVED_32_43,
           INT_VC_AIB_TX_CMD_PRIORITY_RESERVED_32_43_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_RESERVED_32_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_AIB_TX_CMD_PRIORITY_RESERVED_32_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return i_data.extractToRight<INT_VC_AIB_TX_CMD_PRIORITY_RESERVED_32_43,
           INT_VC_AIB_TX_CMD_PRIORITY_RESERVED_32_43_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_RESERVED_32_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_REGS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return o_data.insertFromRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_REGS,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_REGS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_REGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_REGS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return o_data.insertFromRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_REGS,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_REGS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_REGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_REGS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return i_data.extractToRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_REGS,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_REGS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_REGS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ERQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return o_data.insertFromRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ERQ,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ERQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ERQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ERQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return o_data.insertFromRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ERQ,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ERQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ERQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ERQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return i_data.extractToRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ERQ,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ERQ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ERQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_EAS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return o_data.insertFromRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_EAS,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_EAS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_EAS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_EAS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return o_data.insertFromRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_EAS,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_EAS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_EAS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_EAS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return i_data.extractToRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_EAS,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_EAS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_EAS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_SYNC_DONE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return o_data.insertFromRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_SYNC_DONE,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_SYNC_DONE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_SYNC_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_SYNC_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return o_data.insertFromRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_SYNC_DONE,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_SYNC_DONE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_SYNC_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_SYNC_DONE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return i_data.extractToRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_SYNC_DONE,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_SYNC_DONE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_SYNC_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_EOI_RESP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return o_data.insertFromRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_EOI_RESP,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_EOI_RESP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_EOI_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_EOI_RESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return o_data.insertFromRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_EOI_RESP,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_EOI_RESP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_EOI_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_EOI_RESP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return i_data.extractToRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_EOI_RESP,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_EOI_RESP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_EOI_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_DMA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return o_data.insertFromRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_DMA,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_DMA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_DMA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_DMA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return o_data.insertFromRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_DMA,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_DMA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_DMA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_DMA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return i_data.extractToRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_DMA,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_DMA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ESBC_DMA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_CI_STORE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return o_data.insertFromRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_CI_STORE,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_CI_STORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_CI_STORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_CI_STORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return o_data.insertFromRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_CI_STORE,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_CI_STORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_CI_STORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_CI_STORE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return i_data.extractToRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_CI_STORE,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_CI_STORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_CI_STORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_EOI_INT_EQP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return o_data.insertFromRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_EOI_INT_EQP,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_EOI_INT_EQP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_EOI_INT_EQP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_EOI_INT_EQP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return o_data.insertFromRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_EOI_INT_EQP,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_EOI_INT_EQP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_EOI_INT_EQP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_EOI_INT_EQP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return i_data.extractToRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_EOI_INT_EQP,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_EOI_INT_EQP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_EOI_INT_EQP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_NXC_CI_LOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return o_data.insertFromRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_NXC_CI_LOAD,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_NXC_CI_LOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_NXC_CI_LOAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_NXC_CI_LOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return o_data.insertFromRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_NXC_CI_LOAD,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_NXC_CI_LOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_NXC_CI_LOAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_NXC_CI_LOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return i_data.extractToRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_NXC_CI_LOAD,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_NXC_CI_LOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_NXC_CI_LOAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_DMA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return o_data.insertFromRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_DMA,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_DMA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_DMA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_DMA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return o_data.insertFromRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_DMA,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_DMA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_DMA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_DMA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_AIB_TX_CMD_PRIORITY));
#endif
    return i_data.extractToRight<INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_DMA,
           INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_DMA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_AIB_TX_CMD_PRIORITY_ATX_PRIO_FOR_ENDC_DMA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ENDC_CFG_CMD_LIMIT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ENDC_CFG_CMD_LIMIT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ENDC_CFG_CMD_LIMIT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ENDC_CFG_CMD_LIMIT;
#endif
    return fapi2::getScom(i_target, INT_VC_ENDC_CFG_CMD_LIMIT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ENDC_CFG_CMD_LIMIT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return fapi2::putScom(i_target, INT_VC_ENDC_CFG_CMD_LIMIT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_0_1,
           INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_0_1,
           INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return i_data.extractToRight<INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_0_1,
           INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_CRD_POOL_CI_STORE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_CRD_POOL_CI_STORE,
           INT_VC_ENDC_CFG_CMD_LIMIT_CRD_POOL_CI_STORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_CRD_POOL_CI_STORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_CRD_POOL_CI_STORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_CRD_POOL_CI_STORE,
           INT_VC_ENDC_CFG_CMD_LIMIT_CRD_POOL_CI_STORE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_CRD_POOL_CI_STORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_CFG_CMD_LIMIT_CRD_POOL_CI_STORE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return i_data.extractToRight<INT_VC_ENDC_CFG_CMD_LIMIT_CRD_POOL_CI_STORE,
           INT_VC_ENDC_CFG_CMD_LIMIT_CRD_POOL_CI_STORE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_CRD_POOL_CI_STORE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_OS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_OS,
           INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_OS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_OS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_OS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_OS,
           INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_OS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_OS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_OS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return i_data.extractToRight<INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_OS,
           INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_OS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_OS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_OS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_OS,
           INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_OS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_OS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_OS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_OS,
           INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_OS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_OS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_OS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return i_data.extractToRight<INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_OS,
           INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_OS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_OS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_POOL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_POOL,
           INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_POOL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_POOL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_POOL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_POOL,
           INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_POOL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_POOL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_POOL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return i_data.extractToRight<INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_POOL,
           INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_POOL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_POOL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_POOL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_POOL,
           INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_POOL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_POOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_POOL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_POOL,
           INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_POOL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_POOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_POOL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return i_data.extractToRight<INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_POOL,
           INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_POOL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_POOL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_HARD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_HARD,
           INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_HARD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_HARD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_HARD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_HARD,
           INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_HARD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_HARD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_HARD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return i_data.extractToRight<INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_HARD,
           INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_HARD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_RSD_CRD_TRIG_FWD_TO_HARD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_HARD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_HARD,
           INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_HARD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_HARD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_HARD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_HARD,
           INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_HARD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_HARD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_HARD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return i_data.extractToRight<INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_HARD,
           INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_HARD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_CRD_CI_STORE_HARD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_32_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_32_33,
           INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_32_33_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_32_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_32_33,
           INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_32_33_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_32_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return i_data.extractToRight<INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_32_33,
           INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_32_33_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_INT_REQUEST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_INT_REQUEST,
           INT_VC_ENDC_CFG_CMD_LIMIT_INT_REQUEST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_INT_REQUEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_INT_REQUEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_INT_REQUEST,
           INT_VC_ENDC_CFG_CMD_LIMIT_INT_REQUEST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_INT_REQUEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_CFG_CMD_LIMIT_INT_REQUEST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return i_data.extractToRight<INT_VC_ENDC_CFG_CMD_LIMIT_INT_REQUEST,
           INT_VC_ENDC_CFG_CMD_LIMIT_INT_REQUEST_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_INT_REQUEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_EQ_POST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_EQ_POST,
           INT_VC_ENDC_CFG_CMD_LIMIT_EQ_POST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_EQ_POST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_EQ_POST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_EQ_POST,
           INT_VC_ENDC_CFG_CMD_LIMIT_EQ_POST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_EQ_POST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_CFG_CMD_LIMIT_EQ_POST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return i_data.extractToRight<INT_VC_ENDC_CFG_CMD_LIMIT_EQ_POST,
           INT_VC_ENDC_CFG_CMD_LIMIT_EQ_POST_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_EQ_POST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_CI_LOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_CI_LOAD,
           INT_VC_ENDC_CFG_CMD_LIMIT_CI_LOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_CI_LOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_CI_LOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_CI_LOAD,
           INT_VC_ENDC_CFG_CMD_LIMIT_CI_LOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_CI_LOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_CFG_CMD_LIMIT_CI_LOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return i_data.extractToRight<INT_VC_ENDC_CFG_CMD_LIMIT_CI_LOAD,
           INT_VC_ENDC_CFG_CMD_LIMIT_CI_LOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_CI_LOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_READ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_READ,
           INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_READ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_READ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_READ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_READ,
           INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_READ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_READ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_READ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return i_data.extractToRight<INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_READ,
           INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_READ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_READ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_WRITE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_WRITE,
           INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_WRITE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_WRITE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_WRITE,
           INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_WRITE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_WRITE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_CFG_CMD_LIMIT));
#endif
    return i_data.extractToRight<INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_WRITE,
           INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_WRITE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_CFG_CMD_LIMIT_END_DMA_WRITE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ENDC_FLUSH_POLL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ENDC_FLUSH_POLL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ENDC_FLUSH_POLL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ENDC_FLUSH_POLL;
#endif
    return fapi2::getScom(i_target, INT_VC_ENDC_FLUSH_POLL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ENDC_FLUSH_POLL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_POLL));
#endif
    return fapi2::putScom(i_target, INT_VC_ENDC_FLUSH_POLL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_POLL_RESERVED_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_POLL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_POLL_RESERVED_0_3,
           INT_VC_ENDC_FLUSH_POLL_RESERVED_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_POLL_RESERVED_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_POLL_RESERVED_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_POLL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_POLL_RESERVED_0_3,
           INT_VC_ENDC_FLUSH_POLL_RESERVED_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_POLL_RESERVED_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_FLUSH_POLL_RESERVED_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_POLL));
#endif
    return i_data.extractToRight<INT_VC_ENDC_FLUSH_POLL_RESERVED_0_3,
           INT_VC_ENDC_FLUSH_POLL_RESERVED_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_POLL_RESERVED_0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_POLL_BLOCKID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_POLL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_POLL_BLOCKID,
           INT_VC_ENDC_FLUSH_POLL_BLOCKID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_POLL_BLOCKID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_POLL_BLOCKID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_POLL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_POLL_BLOCKID,
           INT_VC_ENDC_FLUSH_POLL_BLOCKID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_POLL_BLOCKID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_FLUSH_POLL_BLOCKID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_POLL));
#endif
    return i_data.extractToRight<INT_VC_ENDC_FLUSH_POLL_BLOCKID,
           INT_VC_ENDC_FLUSH_POLL_BLOCKID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_POLL_BLOCKID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_POLL_OFFSET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_POLL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_POLL_OFFSET,
           INT_VC_ENDC_FLUSH_POLL_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_POLL_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_POLL_OFFSET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_POLL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_POLL_OFFSET,
           INT_VC_ENDC_FLUSH_POLL_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_POLL_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_FLUSH_POLL_OFFSET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_POLL));
#endif
    return i_data.extractToRight<INT_VC_ENDC_FLUSH_POLL_OFFSET,
           INT_VC_ENDC_FLUSH_POLL_OFFSET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_POLL_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_POLL_RESERVED_32_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_POLL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_POLL_RESERVED_32_35,
           INT_VC_ENDC_FLUSH_POLL_RESERVED_32_35_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_POLL_RESERVED_32_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_POLL_RESERVED_32_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_POLL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_POLL_RESERVED_32_35,
           INT_VC_ENDC_FLUSH_POLL_RESERVED_32_35_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_POLL_RESERVED_32_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_FLUSH_POLL_RESERVED_32_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_POLL));
#endif
    return i_data.extractToRight<INT_VC_ENDC_FLUSH_POLL_RESERVED_32_35,
           INT_VC_ENDC_FLUSH_POLL_RESERVED_32_35_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_POLL_RESERVED_32_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_POLL_BLOCKID_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_POLL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_POLL_BLOCKID_MASK,
           INT_VC_ENDC_FLUSH_POLL_BLOCKID_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_POLL_BLOCKID_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_POLL_BLOCKID_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_POLL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_POLL_BLOCKID_MASK,
           INT_VC_ENDC_FLUSH_POLL_BLOCKID_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_POLL_BLOCKID_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_FLUSH_POLL_BLOCKID_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_POLL));
#endif
    return i_data.extractToRight<INT_VC_ENDC_FLUSH_POLL_BLOCKID_MASK,
           INT_VC_ENDC_FLUSH_POLL_BLOCKID_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_POLL_BLOCKID_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_POLL_OFFSET_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_POLL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_POLL_OFFSET_MASK,
           INT_VC_ENDC_FLUSH_POLL_OFFSET_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_POLL_OFFSET_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_FLUSH_POLL_OFFSET_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_POLL));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_FLUSH_POLL_OFFSET_MASK,
           INT_VC_ENDC_FLUSH_POLL_OFFSET_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_POLL_OFFSET_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_FLUSH_POLL_OFFSET_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_FLUSH_POLL));
#endif
    return i_data.extractToRight<INT_VC_ENDC_FLUSH_POLL_OFFSET_MASK,
           INT_VC_ENDC_FLUSH_POLL_OFFSET_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_FLUSH_POLL_OFFSET_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ENDC_PERF_EVENT_SEL_4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ENDC_PERF_EVENT_SEL_4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ENDC_PERF_EVENT_SEL_4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ENDC_PERF_EVENT_SEL_4;
#endif
    return fapi2::getScom(i_target, INT_VC_ENDC_PERF_EVENT_SEL_4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ENDC_PERF_EVENT_SEL_4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return fapi2::putScom(i_target, INT_VC_ENDC_PERF_EVENT_SEL_4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_NXC_TEND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_NXC_TEND,
           INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_NXC_TEND_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_NXC_TEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_NXC_TEND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_NXC_TEND,
           INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_NXC_TEND_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_NXC_TEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_NXC_TEND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_NXC_TEND,
           INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_NXC_TEND_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_NXC_TEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_TCTXT_LD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_TCTXT_LD,
           INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_TCTXT_LD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_TCTXT_LD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_TCTXT_LD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_TCTXT_LD,
           INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_TCTXT_LD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_TCTXT_LD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_TCTXT_LD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_TCTXT_LD,
           INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_TCTXT_LD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_TCTXT_LD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_TCTXT_LD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_TCTXT_LD,
           INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_TCTXT_LD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_TCTXT_LD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_TCTXT_LD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_TCTXT_LD,
           INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_TCTXT_LD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_TCTXT_LD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_TCTXT_LD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_TCTXT_LD,
           INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_TCTXT_LD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_TCTXT_LD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_AUTOGEN_SETPQ00(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_AUTOGEN_SETPQ00,
           INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_AUTOGEN_SETPQ00_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_AUTOGEN_SETPQ00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_AUTOGEN_SETPQ00(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_AUTOGEN_SETPQ00,
           INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_AUTOGEN_SETPQ00_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_AUTOGEN_SETPQ00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_AUTOGEN_SETPQ00(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_AUTOGEN_SETPQ00,
           INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_AUTOGEN_SETPQ00_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_AUTOGEN_SETPQ00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_AUTOGEN_SETPQ00(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_AUTOGEN_SETPQ00,
           INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_AUTOGEN_SETPQ00_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_AUTOGEN_SETPQ00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_AUTOGEN_SETPQ00(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_AUTOGEN_SETPQ00,
           INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_AUTOGEN_SETPQ00_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_AUTOGEN_SETPQ00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_AUTOGEN_SETPQ00(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_AUTOGEN_SETPQ00,
           INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_AUTOGEN_SETPQ00_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_AUTOGEN_SETPQ00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_TRU_ESBC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_TRU_ESBC,
           INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_TRU_ESBC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_TRU_ESBC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_TRU_ESBC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_TRU_ESBC,
           INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_TRU_ESBC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_TRU_ESBC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_TRU_ESBC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_TRU_ESBC,
           INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_TRU_ESBC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_TRU_ESBC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_END_FETCH_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_END_FETCH_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_END_FETCH_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_END_FETCH_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_END_FETCH_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_END_FETCH_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_END_FETCH_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_END_FETCH_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_4_END_FETCH_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_4_END_FETCH_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_END_FETCH_REPLAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_END_FETCH_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_EQ_POST_REPLAY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_EQ_POST_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_EQ_POST_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_EQ_POST_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_EQ_POST_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_EQ_POST_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_EQ_POST_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_EQ_POST_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_4_EQ_POST_REPLAY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_4_EQ_POST_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_EQ_POST_REPLAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_EQ_POST_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_INT_REPLAY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_INT_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_INT_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_INT_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_INT_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_INT_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_INT_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_INT_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_4_INT_REPLAY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_4_INT_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_INT_REPLAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_INT_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_CI_STORE_REPLAY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_CI_STORE_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_CI_STORE_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_CI_STORE_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_CI_STORE_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_CI_STORE_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_CI_STORE_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_CI_STORE_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_4_CI_STORE_REPLAY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_4_CI_STORE_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_CI_STORE_REPLAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_CI_STORE_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_REPLAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESC_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_ESC_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_ESC_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_ESC_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_ESC_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_ESC_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_ESC_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_ESC_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_ESC_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_ESC_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_ESC_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_ESC_REPLAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_REMOTE_ESC_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_NXC_LD_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_NXC_LD_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_NXC_LD_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_NXC_LD_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_NXC_LD_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_NXC_LD_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_NXC_LD_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_NXC_LD_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_NXC_LD_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_NXC_LD_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_NXC_LD_REPLAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_NXC_LD_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESBC_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESBC_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESBC_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESBC_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESBC_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESBC_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESBC_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESBC_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESBC_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESBC_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESBC_REPLAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_LOCAL_ESBC_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_SOFT_LOAD_RESP_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_SOFT_LOAD_RESP_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_SOFT_LOAD_RESP_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_SOFT_LOAD_RESP_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_SOFT_LOAD_RESP_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_SOFT_LOAD_RESP_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_SOFT_LOAD_RESP_REPLAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_SOFT_LOAD_RESP_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_4_SOFT_LOAD_RESP_REPLAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_4_SOFT_LOAD_RESP_REPLAY,
           INT_VC_ENDC_PERF_EVENT_SEL_4_SOFT_LOAD_RESP_REPLAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_SOFT_LOAD_RESP_REPLAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_PROC_UPDATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_PROC_UPDATE,
           INT_VC_ENDC_PERF_EVENT_SEL_4_PROC_UPDATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_PROC_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ENDC_PERF_EVENT_SEL_4_PROC_UPDATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return o_data.insertFromRight<INT_VC_ENDC_PERF_EVENT_SEL_4_PROC_UPDATE,
           INT_VC_ENDC_PERF_EVENT_SEL_4_PROC_UPDATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_PROC_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ENDC_PERF_EVENT_SEL_4_PROC_UPDATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_PERF_EVENT_SEL_4));
#endif
    return i_data.extractToRight<INT_VC_ENDC_PERF_EVENT_SEL_4_PROC_UPDATE,
           INT_VC_ENDC_PERF_EVENT_SEL_4_PROC_UPDATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ENDC_PERF_EVENT_SEL_4_PROC_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ENDC_WATCH1_DATA2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ENDC_WATCH1_DATA2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ENDC_WATCH1_DATA2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ENDC_WATCH1_DATA2;
#endif
    return fapi2::getScom(i_target, INT_VC_ENDC_WATCH1_DATA2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ENDC_WATCH1_DATA2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_ENDC_WATCH1_DATA2));
#endif
    return fapi2::putScom(i_target, INT_VC_ENDC_WATCH1_DATA2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_ESB_BLOCK_MODE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ESB_BLOCK_MODE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_ESB_BLOCK_MODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_ESB_BLOCK_MODE;
#endif
    return fapi2::getScom(i_target, INT_VC_ESB_BLOCK_MODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_ESB_BLOCK_MODE(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_ESB_BLOCK_MODE));
#endif
    return fapi2::putScom(i_target, INT_VC_ESB_BLOCK_MODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESB_BLOCK_MODE_INT_VC_ESB_BLOCK_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESB_BLOCK_MODE));
#endif
    return o_data.insertFromRight<INT_VC_ESB_BLOCK_MODE_INT_VC_ESB_BLOCK_MODE,
           INT_VC_ESB_BLOCK_MODE_INT_VC_ESB_BLOCK_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESB_BLOCK_MODE_INT_VC_ESB_BLOCK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_ESB_BLOCK_MODE_INT_VC_ESB_BLOCK_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESB_BLOCK_MODE));
#endif
    return o_data.insertFromRight<INT_VC_ESB_BLOCK_MODE_INT_VC_ESB_BLOCK_MODE,
           INT_VC_ESB_BLOCK_MODE_INT_VC_ESB_BLOCK_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESB_BLOCK_MODE_INT_VC_ESB_BLOCK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_ESB_BLOCK_MODE_INT_VC_ESB_BLOCK_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_ESB_BLOCK_MODE));
#endif
    return i_data.extractToRight<INT_VC_ESB_BLOCK_MODE_INT_VC_ESB_BLOCK_MODE,
           INT_VC_ESB_BLOCK_MODE_INT_VC_ESB_BLOCK_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_ESB_BLOCK_MODE_INT_VC_ESB_BLOCK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_NVPG_BLOCK_MODE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_NVPG_BLOCK_MODE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_NVPG_BLOCK_MODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_NVPG_BLOCK_MODE;
#endif
    return fapi2::getScom(i_target, INT_VC_NVPG_BLOCK_MODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_NVPG_BLOCK_MODE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_NVPG_BLOCK_MODE));
#endif
    return fapi2::putScom(i_target, INT_VC_NVPG_BLOCK_MODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_NVPG_BLOCK_MODE_INT_VC_NVPG_BLOCK_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_NVPG_BLOCK_MODE));
#endif
    return o_data.insertFromRight<INT_VC_NVPG_BLOCK_MODE_INT_VC_NVPG_BLOCK_MODE,
           INT_VC_NVPG_BLOCK_MODE_INT_VC_NVPG_BLOCK_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_NVPG_BLOCK_MODE_INT_VC_NVPG_BLOCK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_NVPG_BLOCK_MODE_INT_VC_NVPG_BLOCK_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_NVPG_BLOCK_MODE));
#endif
    return o_data.insertFromRight<INT_VC_NVPG_BLOCK_MODE_INT_VC_NVPG_BLOCK_MODE,
           INT_VC_NVPG_BLOCK_MODE_INT_VC_NVPG_BLOCK_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_NVPG_BLOCK_MODE_INT_VC_NVPG_BLOCK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_NVPG_BLOCK_MODE_INT_VC_NVPG_BLOCK_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_NVPG_BLOCK_MODE));
#endif
    return i_data.extractToRight<INT_VC_NVPG_BLOCK_MODE_INT_VC_NVPG_BLOCK_MODE,
           INT_VC_NVPG_BLOCK_MODE_INT_VC_NVPG_BLOCK_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_NVPG_BLOCK_MODE_INT_VC_NVPG_BLOCK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_QUEUES_CFG_REM_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_QUEUES_CFG_REM_3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_QUEUES_CFG_REM_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_QUEUES_CFG_REM_3;
#endif
    return fapi2::getScom(i_target, INT_VC_QUEUES_CFG_REM_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_QUEUES_CFG_REM_3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return fapi2::putScom(i_target, INT_VC_QUEUES_CFG_REM_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_IRQ_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_IRQ_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_IRQ_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_IRQ_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_IRQ_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_3_IRQ_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_3_IRQ_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_3_IRQ_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_3_IRQ_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_3_IRQ_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_3_IRQ_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_3_IRQ_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_IRQ_DROP_EQ_INJECT_FROM_CORE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_IRQ_DROP_EQ_INJECT_FROM_CORE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_DROP_EQ_INJECT_FROM_CORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_IRQ_DROP_EQ_INJECT_FROM_CORE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_IRQ_DROP_EQ_INJECT_FROM_CORE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_DROP_EQ_INJECT_FROM_CORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_IRQ_DROP_EQ_INJECT_FROM_CORE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_3_IRQ_DROP_EQ_INJECT_FROM_CORE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_DROP_EQ_INJECT_FROM_CORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_3_IRQ_DROP_EQ_INJECT_FROM_CORE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_3_IRQ_DROP_EQ_INJECT_FROM_CORE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_DROP_EQ_INJECT_FROM_CORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_3_IRQ_DROP_EQ_INJECT_FROM_CORE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_3_IRQ_DROP_EQ_INJECT_FROM_CORE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_DROP_EQ_INJECT_FROM_CORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_3_IRQ_DROP_EQ_INJECT_FROM_CORE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_3_IRQ_DROP_EQ_INJECT_FROM_CORE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_DROP_EQ_INJECT_FROM_CORE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_IRQ_PREFETCH_DISTANCE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_IRQ_PREFETCH_DISTANCE,
           INT_VC_QUEUES_CFG_REM_3_IRQ_PREFETCH_DISTANCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_PREFETCH_DISTANCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_IRQ_PREFETCH_DISTANCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_IRQ_PREFETCH_DISTANCE,
           INT_VC_QUEUES_CFG_REM_3_IRQ_PREFETCH_DISTANCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_PREFETCH_DISTANCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_3_IRQ_PREFETCH_DISTANCE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_3_IRQ_PREFETCH_DISTANCE,
           INT_VC_QUEUES_CFG_REM_3_IRQ_PREFETCH_DISTANCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_PREFETCH_DISTANCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_RESERVED_8_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_RESERVED_8_10,
           INT_VC_QUEUES_CFG_REM_3_RESERVED_8_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_RESERVED_8_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_RESERVED_8_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_RESERVED_8_10,
           INT_VC_QUEUES_CFG_REM_3_RESERVED_8_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_RESERVED_8_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_3_RESERVED_8_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_3_RESERVED_8_10,
           INT_VC_QUEUES_CFG_REM_3_RESERVED_8_10_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_RESERVED_8_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_CQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_CQ,
           INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_CQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_CQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_CQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_CQ,
           INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_CQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_CQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_CQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_CQ,
           INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_CQ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_CQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_RESERVED_16_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_RESERVED_16_18,
           INT_VC_QUEUES_CFG_REM_3_RESERVED_16_18_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_RESERVED_16_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_RESERVED_16_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_RESERVED_16_18,
           INT_VC_QUEUES_CFG_REM_3_RESERVED_16_18_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_RESERVED_16_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_3_RESERVED_16_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_3_RESERVED_16_18,
           INT_VC_QUEUES_CFG_REM_3_RESERVED_16_18_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_RESERVED_16_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_PC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_PC,
           INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_PC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_PC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_PC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_PC,
           INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_PC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_PC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_PC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_PC,
           INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_PC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_CRD_TO_PC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_NB_OUTSTANDING_DEM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_NB_OUTSTANDING_DEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_NB_OUTSTANDING_DEM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_NB_OUTSTANDING_DEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_NB_OUTSTANDING_DEM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_NB_OUTSTANDING_DEM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_MAX_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_IRQ_MIN_NB_OUTSTANDING_DEM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_IRQ_MIN_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_REM_3_IRQ_MIN_NB_OUTSTANDING_DEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_MIN_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_IRQ_MIN_NB_OUTSTANDING_DEM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_IRQ_MIN_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_REM_3_IRQ_MIN_NB_OUTSTANDING_DEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_MIN_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_3_IRQ_MIN_NB_OUTSTANDING_DEM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_3_IRQ_MIN_NB_OUTSTANDING_DEM,
           INT_VC_QUEUES_CFG_REM_3_IRQ_MIN_NB_OUTSTANDING_DEM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_MIN_NB_OUTSTANDING_DEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_RESERVED_32_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_RESERVED_32_33,
           INT_VC_QUEUES_CFG_REM_3_RESERVED_32_33_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_RESERVED_32_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_RESERVED_32_33,
           INT_VC_QUEUES_CFG_REM_3_RESERVED_32_33_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_3_RESERVED_32_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_3_RESERVED_32_33,
           INT_VC_QUEUES_CFG_REM_3_RESERVED_32_33_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_RESERVED_32_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_IRQ_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_IRQ_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_IRQ_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_IRQ_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_IRQ_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_3_IRQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_3_IRQ_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_3_IRQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_3_IRQ_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_3_IRQ_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_3_IRQ_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_3_IRQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_IRQ_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_IRQ_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_IRQ_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_IRQ_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_IRQ_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_3_IRQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_3_IRQ_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_3_IRQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_3_IRQ_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_3_IRQ_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_3_IRQ_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_3_IRQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_IRQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_RESERVED_36_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_RESERVED_36_37,
           INT_VC_QUEUES_CFG_REM_3_RESERVED_36_37_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_RESERVED_36_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_RESERVED_36_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_RESERVED_36_37,
           INT_VC_QUEUES_CFG_REM_3_RESERVED_36_37_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_RESERVED_36_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_3_RESERVED_36_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_3_RESERVED_36_37,
           INT_VC_QUEUES_CFG_REM_3_RESERVED_36_37_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_RESERVED_36_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_ERQ_ENABLE_MEMORY_BACKING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_ERQ_ENABLE_MEMORY_BACKING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_ENABLE_MEMORY_BACKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_ERQ_ENABLE_MEMORY_BACKING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_ERQ_ENABLE_MEMORY_BACKING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_ENABLE_MEMORY_BACKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_ERQ_ENABLE_MEMORY_BACKING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_3_ERQ_ENABLE_MEMORY_BACKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_ENABLE_MEMORY_BACKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_3_ERQ_ENABLE_MEMORY_BACKING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_3_ERQ_ENABLE_MEMORY_BACKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_ENABLE_MEMORY_BACKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_3_ERQ_ENABLE_MEMORY_BACKING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_3_ERQ_ENABLE_MEMORY_BACKING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_ENABLE_MEMORY_BACKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_3_ERQ_ENABLE_MEMORY_BACKING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_3_ERQ_ENABLE_MEMORY_BACKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_ENABLE_MEMORY_BACKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_ERQ_FULL_WRITEBACK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_ERQ_FULL_WRITEBACK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_FULL_WRITEBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_ERQ_FULL_WRITEBACK_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_ERQ_FULL_WRITEBACK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_FULL_WRITEBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_ERQ_FULL_WRITEBACK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_3_ERQ_FULL_WRITEBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_FULL_WRITEBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_3_ERQ_FULL_WRITEBACK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_3_ERQ_FULL_WRITEBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_FULL_WRITEBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_3_ERQ_FULL_WRITEBACK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_3_ERQ_FULL_WRITEBACK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_FULL_WRITEBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_3_ERQ_FULL_WRITEBACK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_3_ERQ_FULL_WRITEBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_FULL_WRITEBACK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_RESERVED_40_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_RESERVED_40_41,
           INT_VC_QUEUES_CFG_REM_3_RESERVED_40_41_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_RESERVED_40_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_RESERVED_40_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_RESERVED_40_41,
           INT_VC_QUEUES_CFG_REM_3_RESERVED_40_41_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_RESERVED_40_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_3_RESERVED_40_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_3_RESERVED_40_41,
           INT_VC_QUEUES_CFG_REM_3_RESERVED_40_41_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_RESERVED_40_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_ERQ_MEM_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_ERQ_MEM_SIZE,
           INT_VC_QUEUES_CFG_REM_3_ERQ_MEM_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_MEM_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_ERQ_MEM_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_ERQ_MEM_SIZE,
           INT_VC_QUEUES_CFG_REM_3_ERQ_MEM_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_MEM_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_3_ERQ_MEM_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_3_ERQ_MEM_SIZE,
           INT_VC_QUEUES_CFG_REM_3_ERQ_MEM_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_MEM_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_RESERVED_48_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_RESERVED_48_49,
           INT_VC_QUEUES_CFG_REM_3_RESERVED_48_49_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_RESERVED_48_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_RESERVED_48_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_RESERVED_48_49,
           INT_VC_QUEUES_CFG_REM_3_RESERVED_48_49_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_RESERVED_48_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_3_RESERVED_48_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_3_RESERVED_48_49,
           INT_VC_QUEUES_CFG_REM_3_RESERVED_48_49_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_RESERVED_48_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_ERQ_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_ERQ_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_ERQ_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_ERQ_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_ERQ_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_3_ERQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_3_ERQ_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_3_ERQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_3_ERQ_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_3_ERQ_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_3_ERQ_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_3_ERQ_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_ERQ_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_ERQ_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_ERQ_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_ERQ_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_ERQ_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_3_ERQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_3_ERQ_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_3_ERQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_3_ERQ_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_3_ERQ_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_3_ERQ_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_3_ERQ_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_ERQ_CFG_UPD_PND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_ERQ_CFG_UPD_PND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_CFG_UPD_PND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_ERQ_CFG_UPD_PND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_CFG_REM_3_ERQ_CFG_UPD_PND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_CFG_UPD_PND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_CFG_REM_3_ERQ_CFG_UPD_PND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.setBit<INT_VC_QUEUES_CFG_REM_3_ERQ_CFG_UPD_PND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_CFG_UPD_PND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_INT_VC_QUEUES_CFG_REM_3_ERQ_CFG_UPD_PND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return o_data.clearBit<INT_VC_QUEUES_CFG_REM_3_ERQ_CFG_UPD_PND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_CFG_UPD_PND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_CFG_REM_3_ERQ_CFG_UPD_PND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_CFG_REM_3_ERQ_CFG_UPD_PND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_CFG_UPD_PND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_INT_VC_QUEUES_CFG_REM_3_ERQ_CFG_UPD_PND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_CFG_REM_3));
#endif
    return i_data.getBit<INT_VC_QUEUES_CFG_REM_3_ERQ_CFG_UPD_PND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_CFG_REM_3_ERQ_CFG_UPD_PND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_INT_VC_QUEUES_PERF_EVENT_SEL_0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_QUEUES_PERF_EVENT_SEL_0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_INT_VC_QUEUES_PERF_EVENT_SEL_0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = INT_VC_QUEUES_PERF_EVENT_SEL_0;
#endif
    return fapi2::getScom(i_target, INT_VC_QUEUES_PERF_EVENT_SEL_0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_INT_VC_QUEUES_PERF_EVENT_SEL_0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return fapi2::putScom(i_target, INT_VC_QUEUES_PERF_EVENT_SEL_0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_0_FROM_AIB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_0_FROM_AIB,
           INT_VC_QUEUES_PERF_EVENT_SEL_0_FROM_AIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_0_FROM_AIB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_0_FROM_AIB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_0_FROM_AIB,
           INT_VC_QUEUES_PERF_EVENT_SEL_0_FROM_AIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_0_FROM_AIB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_0_FROM_AIB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_0_FROM_AIB,
           INT_VC_QUEUES_PERF_EVENT_SEL_0_FROM_AIB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_0_FROM_AIB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_0_IRQ_TO_IQA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_0_IRQ_TO_IQA,
           INT_VC_QUEUES_PERF_EVENT_SEL_0_IRQ_TO_IQA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_0_IRQ_TO_IQA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_0_IRQ_TO_IQA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_0_IRQ_TO_IQA,
           INT_VC_QUEUES_PERF_EVENT_SEL_0_IRQ_TO_IQA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_0_IRQ_TO_IQA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_0_IRQ_TO_IQA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_0_IRQ_TO_IQA,
           INT_VC_QUEUES_PERF_EVENT_SEL_0_IRQ_TO_IQA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_0_IRQ_TO_IQA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_DPS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_DPS,
           INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_DPS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_DPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_DPS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_DPS,
           INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_DPS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_DPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_DPS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_DPS,
           INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_DPS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_DPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_IQS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_IQS,
           INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_IQS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_IQS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_IQS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_IQS,
           INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_IQS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_IQS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_IQS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_IQS,
           INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_IQS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_0_IQA_TO_IQS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_0_IQS_TO_EQA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_0_IQS_TO_EQA,
           INT_VC_QUEUES_PERF_EVENT_SEL_0_IQS_TO_EQA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_0_IQS_TO_EQA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_0_IQS_TO_EQA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_0_IQS_TO_EQA,
           INT_VC_QUEUES_PERF_EVENT_SEL_0_IQS_TO_EQA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_0_IQS_TO_EQA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_0_IQS_TO_EQA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_0_IQS_TO_EQA,
           INT_VC_QUEUES_PERF_EVENT_SEL_0_IQS_TO_EQA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_0_IQS_TO_EQA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ERQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ERQ,
           INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ERQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ERQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ERQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ERQ,
           INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ERQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ERQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ERQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ERQ,
           INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ERQ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ERQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ATX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ATX,
           INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ATX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ATX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ATX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ATX,
           INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ATX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ATX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ATX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ATX,
           INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ATX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ATX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ENDC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ENDC,
           INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ENDC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ENDC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ENDC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return o_data.insertFromRight<INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ENDC,
           INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ENDC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ENDC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ENDC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(INT_VC_QUEUES_PERF_EVENT_SEL_0));
#endif
    return i_data.extractToRight<INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ENDC,
           INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ENDC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access INT_VC_QUEUES_PERF_EVENT_SEL_0_EQA_TO_ENDC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_BANK0_STR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_BANK0_STR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_BANK0_STR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_BANK0_STR;
#endif
    return fapi2::getScom(i_target, MCD_BANK0_STR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_BANK0_STR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return fapi2::putScom(i_target, MCD_BANK0_STR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.setBit<MCD_BANK0_STR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_STR_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.clearBit<MCD_BANK0_STR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_STR_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return i_data.extractToRight<MCD_BANK0_STR_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_STR_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return i_data.getBit<MCD_BANK0_STR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_CPG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_CPG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_CPG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_CPG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_CPG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.setBit<MCD_BANK0_STR_CPG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_STR_CPG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.clearBit<MCD_BANK0_STR_CPG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_STR_CPG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return i_data.extractToRight<MCD_BANK0_STR_CPG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_STR_CPG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return i_data.getBit<MCD_BANK0_STR_CPG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_CPG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_GRP_MBR_ID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_GRP_MBR_ID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_GRP_MBR_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_GRP_MBR_ID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_GRP_MBR_ID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.setBit<MCD_BANK0_STR_GRP_MBR_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_STR_GRP_MBR_ID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.clearBit<MCD_BANK0_STR_GRP_MBR_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_STR_GRP_MBR_ID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return i_data.extractToRight<MCD_BANK0_STR_GRP_MBR_ID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_STR_GRP_MBR_ID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return i_data.getBit<MCD_BANK0_STR_GRP_MBR_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_GRP_MBR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_ALWAYS_RTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_ALWAYS_RTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_ALWAYS_RTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_ALWAYS_RTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_ALWAYS_RTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.setBit<MCD_BANK0_STR_ALWAYS_RTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_STR_ALWAYS_RTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.clearBit<MCD_BANK0_STR_ALWAYS_RTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_STR_ALWAYS_RTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return i_data.extractToRight<MCD_BANK0_STR_ALWAYS_RTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_STR_ALWAYS_RTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return i_data.getBit<MCD_BANK0_STR_ALWAYS_RTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_ALWAYS_RTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_SMF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_SMF_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_SMF_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_SMF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.setBit<MCD_BANK0_STR_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MCD_BANK0_STR_SMF_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.clearBit<MCD_BANK0_STR_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_STR_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return i_data.extractToRight<MCD_BANK0_STR_SMF_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MCD_BANK0_STR_SMF_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return i_data.getBit<MCD_BANK0_STR_SMF_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_SMF_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_GRP_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_GRP_SIZE,
           MCD_BANK0_STR_GRP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_GRP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_GRP_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_GRP_SIZE,
           MCD_BANK0_STR_GRP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_GRP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_STR_GRP_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return i_data.extractToRight<MCD_BANK0_STR_GRP_SIZE,
           MCD_BANK0_STR_GRP_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_GRP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_GRP_BASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_GRP_BASE,
           MCD_BANK0_STR_GRP_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_GRP_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MCD_BANK0_STR_GRP_BASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return o_data.insertFromRight<MCD_BANK0_STR_GRP_BASE,
           MCD_BANK0_STR_GRP_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_GRP_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MCD_BANK0_STR_GRP_BASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_BANK0_STR));
#endif
    return i_data.extractToRight<MCD_BANK0_STR_GRP_BASE,
           MCD_BANK0_STR_GRP_BASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MCD_BANK0_STR_GRP_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_CH4_ADDR_8_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_CH4_ADDR_8_HASH_FUNCTION_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_CH4_ADDR_8_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_CH4_ADDR_8_HASH_FUNCTION_REG;
#endif
    return fapi2::getScom(i_target, NX_CH4_ADDR_8_HASH_FUNCTION_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_CH4_ADDR_8_HASH_FUNCTION_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_CH4_ADDR_8_HASH_FUNCTION_REG));
#endif
    return fapi2::putScom(i_target, NX_CH4_ADDR_8_HASH_FUNCTION_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_CH4_ADDR_8_HASH_FUNCTION_REG_ADDRESS_8_HASH_FUNCTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_ADDR_8_HASH_FUNCTION_REG));
#endif
    return o_data.insertFromRight<NX_CH4_ADDR_8_HASH_FUNCTION_REG_ADDRESS_8_HASH_FUNCTION,
           NX_CH4_ADDR_8_HASH_FUNCTION_REG_ADDRESS_8_HASH_FUNCTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_ADDR_8_HASH_FUNCTION_REG_ADDRESS_8_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_CH4_ADDR_8_HASH_FUNCTION_REG_ADDRESS_8_HASH_FUNCTION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_ADDR_8_HASH_FUNCTION_REG));
#endif
    return o_data.insertFromRight<NX_CH4_ADDR_8_HASH_FUNCTION_REG_ADDRESS_8_HASH_FUNCTION,
           NX_CH4_ADDR_8_HASH_FUNCTION_REG_ADDRESS_8_HASH_FUNCTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_ADDR_8_HASH_FUNCTION_REG_ADDRESS_8_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_CH4_ADDR_8_HASH_FUNCTION_REG_ADDRESS_8_HASH_FUNCTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_CH4_ADDR_8_HASH_FUNCTION_REG));
#endif
    return i_data.extractToRight<NX_CH4_ADDR_8_HASH_FUNCTION_REG_ADDRESS_8_HASH_FUNCTION,
           NX_CH4_ADDR_8_HASH_FUNCTION_REG_ADDRESS_8_HASH_FUNCTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_CH4_ADDR_8_HASH_FUNCTION_REG_ADDRESS_8_HASH_FUNCTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_DBG_TRIGGER_CTRL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_DBG_TRIGGER_CTRL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_DBG_TRIGGER_CTRL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_DBG_TRIGGER_CTRL;
#endif
    return fapi2::getScom(i_target, NX_DBG_TRIGGER_CTRL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_DBG_TRIGGER_CTRL(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_DBG_TRIGGER_CTRL));
#endif
    return fapi2::putScom(i_target, NX_DBG_TRIGGER_CTRL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_DBG_TRIGGER_CTRL_NX_TRIGGER_CTRL_BITS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DBG_TRIGGER_CTRL));
#endif
    return o_data.insertFromRight<NX_DBG_TRIGGER_CTRL_NX_TRIGGER_CTRL_BITS,
           NX_DBG_TRIGGER_CTRL_NX_TRIGGER_CTRL_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DBG_TRIGGER_CTRL_NX_TRIGGER_CTRL_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DBG_TRIGGER_CTRL_NX_TRIGGER_CTRL_BITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DBG_TRIGGER_CTRL));
#endif
    return o_data.insertFromRight<NX_DBG_TRIGGER_CTRL_NX_TRIGGER_CTRL_BITS,
           NX_DBG_TRIGGER_CTRL_NX_TRIGGER_CTRL_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DBG_TRIGGER_CTRL_NX_TRIGGER_CTRL_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DBG_TRIGGER_CTRL_NX_TRIGGER_CTRL_BITS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DBG_TRIGGER_CTRL));
#endif
    return i_data.extractToRight<NX_DBG_TRIGGER_CTRL_NX_TRIGGER_CTRL_BITS,
           NX_DBG_TRIGGER_CTRL_NX_TRIGGER_CTRL_BITS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DBG_TRIGGER_CTRL_NX_TRIGGER_CTRL_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_DMA_GZIP_MAX_BYTE_CNT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_DMA_GZIP_MAX_BYTE_CNT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_DMA_GZIP_MAX_BYTE_CNT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_DMA_GZIP_MAX_BYTE_CNT;
#endif
    return fapi2::getScom(i_target, NX_DMA_GZIP_MAX_BYTE_CNT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_DMA_GZIP_MAX_BYTE_CNT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_DMA_GZIP_MAX_BYTE_CNT));
#endif
    return fapi2::putScom(i_target, NX_DMA_GZIP_MAX_BYTE_CNT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_LOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_GZIP_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_LOW,
           NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_LOW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_LOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_LOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_GZIP_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_LOW,
           NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_LOW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_LOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_LOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_GZIP_MAX_BYTE_CNT));
#endif
    return i_data.extractToRight<NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_LOW,
           NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_LOW_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_LOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_HIGH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_GZIP_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_HIGH,
           NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_HIGH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_HIGH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_HIGH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_GZIP_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_HIGH,
           NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_HIGH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_HIGH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_HIGH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_GZIP_MAX_BYTE_CNT));
#endif
    return i_data.extractToRight<NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_HIGH,
           NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_HIGH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_HIGH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_GZIP_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_GZIP_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_THRESHOLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_GZIP_MAX_BYTE_CNT));
#endif
    return o_data.setBit<NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_THRESHOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_GZIP_MAX_BYTE_CNT));
#endif
    return o_data.clearBit<NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_GZIP_MAX_BYTE_CNT));
#endif
    return i_data.extractToRight<NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_THRESHOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_THRESHOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_GZIP_MAX_BYTE_CNT));
#endif
    return i_data.getBit<NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_GZIP_MAX_BYTE_CNT_BYTE_CNT_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_GZIP_MAX_BYTE_CNT_SRC_DDE_CNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_GZIP_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_GZIP_MAX_BYTE_CNT_SRC_DDE_CNT,
           NX_DMA_GZIP_MAX_BYTE_CNT_SRC_DDE_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_GZIP_MAX_BYTE_CNT_SRC_DDE_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_GZIP_MAX_BYTE_CNT_SRC_DDE_CNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_GZIP_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_GZIP_MAX_BYTE_CNT_SRC_DDE_CNT,
           NX_DMA_GZIP_MAX_BYTE_CNT_SRC_DDE_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_GZIP_MAX_BYTE_CNT_SRC_DDE_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_GZIP_MAX_BYTE_CNT_SRC_DDE_CNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_GZIP_MAX_BYTE_CNT));
#endif
    return i_data.extractToRight<NX_DMA_GZIP_MAX_BYTE_CNT_SRC_DDE_CNT,
           NX_DMA_GZIP_MAX_BYTE_CNT_SRC_DDE_CNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_GZIP_MAX_BYTE_CNT_SRC_DDE_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_GZIP_MAX_BYTE_CNT_TARGET_DDE_CNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_GZIP_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_GZIP_MAX_BYTE_CNT_TARGET_DDE_CNT,
           NX_DMA_GZIP_MAX_BYTE_CNT_TARGET_DDE_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_GZIP_MAX_BYTE_CNT_TARGET_DDE_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_GZIP_MAX_BYTE_CNT_TARGET_DDE_CNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_GZIP_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_GZIP_MAX_BYTE_CNT_TARGET_DDE_CNT,
           NX_DMA_GZIP_MAX_BYTE_CNT_TARGET_DDE_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_GZIP_MAX_BYTE_CNT_TARGET_DDE_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_GZIP_MAX_BYTE_CNT_TARGET_DDE_CNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_GZIP_MAX_BYTE_CNT));
#endif
    return i_data.extractToRight<NX_DMA_GZIP_MAX_BYTE_CNT_TARGET_DDE_CNT,
           NX_DMA_GZIP_MAX_BYTE_CNT_TARGET_DDE_CNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_GZIP_MAX_BYTE_CNT_TARGET_DDE_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_DMA_SYM_MAX_BYTE_CNT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_DMA_SYM_MAX_BYTE_CNT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_DMA_SYM_MAX_BYTE_CNT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_DMA_SYM_MAX_BYTE_CNT;
#endif
    return fapi2::getScom(i_target, NX_DMA_SYM_MAX_BYTE_CNT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_DMA_SYM_MAX_BYTE_CNT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_DMA_SYM_MAX_BYTE_CNT));
#endif
    return fapi2::putScom(i_target, NX_DMA_SYM_MAX_BYTE_CNT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SYM_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SYM_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_SYM_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT,
           NX_DMA_SYM_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SYM_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SYM_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SYM_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_SYM_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT,
           NX_DMA_SYM_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SYM_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SYM_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SYM_MAX_BYTE_CNT));
#endif
    return i_data.extractToRight<NX_DMA_SYM_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT,
           NX_DMA_SYM_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SYM_MAX_BYTE_CNT_MAX_BYTE_CNT_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SYM_MAX_BYTE_CNT_MAX_SRC_DDE_CNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SYM_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_SYM_MAX_BYTE_CNT_MAX_SRC_DDE_CNT,
           NX_DMA_SYM_MAX_BYTE_CNT_MAX_SRC_DDE_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SYM_MAX_BYTE_CNT_MAX_SRC_DDE_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SYM_MAX_BYTE_CNT_MAX_SRC_DDE_CNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SYM_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_SYM_MAX_BYTE_CNT_MAX_SRC_DDE_CNT,
           NX_DMA_SYM_MAX_BYTE_CNT_MAX_SRC_DDE_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SYM_MAX_BYTE_CNT_MAX_SRC_DDE_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SYM_MAX_BYTE_CNT_MAX_SRC_DDE_CNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SYM_MAX_BYTE_CNT));
#endif
    return i_data.extractToRight<NX_DMA_SYM_MAX_BYTE_CNT_MAX_SRC_DDE_CNT,
           NX_DMA_SYM_MAX_BYTE_CNT_MAX_SRC_DDE_CNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SYM_MAX_BYTE_CNT_MAX_SRC_DDE_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SYM_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SYM_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_SYM_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT,
           NX_DMA_SYM_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SYM_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SYM_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SYM_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_SYM_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT,
           NX_DMA_SYM_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SYM_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SYM_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SYM_MAX_BYTE_CNT));
#endif
    return i_data.extractToRight<NX_DMA_SYM_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT,
           NX_DMA_SYM_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SYM_MAX_BYTE_CNT_MAX_TARGET_DDE_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SYM_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SYM_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_SYM_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT,
           NX_DMA_SYM_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SYM_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_DMA_SYM_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SYM_MAX_BYTE_CNT));
#endif
    return o_data.insertFromRight<NX_DMA_SYM_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT,
           NX_DMA_SYM_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SYM_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_DMA_SYM_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_DMA_SYM_MAX_BYTE_CNT));
#endif
    return i_data.extractToRight<NX_DMA_SYM_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT,
           NX_DMA_SYM_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_DMA_SYM_MAX_BYTE_CNT_LO_PRIOR_MAX_BYTE_CNT_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG;
#endif
    return fapi2::getScom(i_target, NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG));
#endif
    return fapi2::putScom(i_target, NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG));
#endif
    return i_data.extractToRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL0_REG_TOPOID_XLAT_TBL_ENTRIES_00_07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG;
#endif
    return fapi2::getScom(i_target, NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG));
#endif
    return fapi2::putScom(i_target, NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG_TOPOID_XLAT_TBL_ENTRIES_08_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG_TOPOID_XLAT_TBL_ENTRIES_08_15,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG_TOPOID_XLAT_TBL_ENTRIES_08_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG_TOPOID_XLAT_TBL_ENTRIES_08_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG_TOPOID_XLAT_TBL_ENTRIES_08_15(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG_TOPOID_XLAT_TBL_ENTRIES_08_15,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG_TOPOID_XLAT_TBL_ENTRIES_08_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG_TOPOID_XLAT_TBL_ENTRIES_08_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG_TOPOID_XLAT_TBL_ENTRIES_08_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG));
#endif
    return i_data.extractToRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG_TOPOID_XLAT_TBL_ENTRIES_08_15,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG_TOPOID_XLAT_TBL_ENTRIES_08_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL1_REG_TOPOID_XLAT_TBL_ENTRIES_08_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG;
#endif
    return fapi2::getScom(i_target, NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG));
#endif
    return fapi2::putScom(i_target, NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG_TOPOID_XLAT_TBL_ENTRIES_16_23(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG_TOPOID_XLAT_TBL_ENTRIES_16_23,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG_TOPOID_XLAT_TBL_ENTRIES_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG_TOPOID_XLAT_TBL_ENTRIES_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG_TOPOID_XLAT_TBL_ENTRIES_16_23(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG_TOPOID_XLAT_TBL_ENTRIES_16_23,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG_TOPOID_XLAT_TBL_ENTRIES_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG_TOPOID_XLAT_TBL_ENTRIES_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG_TOPOID_XLAT_TBL_ENTRIES_16_23(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG));
#endif
    return i_data.extractToRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG_TOPOID_XLAT_TBL_ENTRIES_16_23,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG_TOPOID_XLAT_TBL_ENTRIES_16_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL2_REG_TOPOID_XLAT_TBL_ENTRIES_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG;
#endif
    return fapi2::getScom(i_target, NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG));
#endif
    return fapi2::putScom(i_target, NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG_TOPOID_XLAT_TBL_ENTRIES_24_31(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG_TOPOID_XLAT_TBL_ENTRIES_24_31,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG_TOPOID_XLAT_TBL_ENTRIES_24_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG_TOPOID_XLAT_TBL_ENTRIES_24_31 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG_TOPOID_XLAT_TBL_ENTRIES_24_31(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG));
#endif
    return o_data.insertFromRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG_TOPOID_XLAT_TBL_ENTRIES_24_31,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG_TOPOID_XLAT_TBL_ENTRIES_24_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG_TOPOID_XLAT_TBL_ENTRIES_24_31 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG_TOPOID_XLAT_TBL_ENTRIES_24_31(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG));
#endif
    return i_data.extractToRight<NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG_TOPOID_XLAT_TBL_ENTRIES_24_31,
           NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG_TOPOID_XLAT_TBL_ENTRIES_24_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_CQ_WRAP_NXCQ_SCOM_TOPOID_XLAT_TBL3_REG_TOPOID_XLAT_TBL_ENTRIES_24_31 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_RNG_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_RNG_CFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_RNG_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_RNG_CFG;
#endif
    return fapi2::getScom(i_target, NX_PBI_RNG_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_RNG_CFG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return fapi2::putScom(i_target, NX_PBI_RNG_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_FAIL_REG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_FAIL_REG,
           NX_PBI_RNG_CFG_FAIL_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_FAIL_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_FAIL_REG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_FAIL_REG,
           NX_PBI_RNG_CFG_FAIL_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_FAIL_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_FAIL_REG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_FAIL_REG,
           NX_PBI_RNG_CFG_FAIL_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_FAIL_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG0_FAIL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG0_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG0_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG0_FAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG0_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG0_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG0_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_RNG0_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG0_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_RNG0_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_RNG0_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG0_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_RNG0_FAIL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_RNG0_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG0_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_PBI_RNG_CFG_RNG0_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_RNG0_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG0_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG1_FAIL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG1_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG1_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG1_FAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG1_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG1_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG1_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_RNG1_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG1_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_RNG1_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_RNG1_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG1_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_RNG1_FAIL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_RNG1_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG1_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_PBI_RNG_CFG_RNG1_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_RNG1_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG1_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_INTERRUPT_SENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_INTERRUPT_SENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_INTERRUPT_SENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_INTERRUPT_SENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_INTERRUPT_SENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_INTERRUPT_SENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_INTERRUPT_SENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_INTERRUPT_SENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_INTERRUPT_SENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_INTERRUPT_SENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_INTERRUPT_SENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_INTERRUPT_SENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_INTERRUPT_SENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_INTERRUPT_SENT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_INTERRUPT_SENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_PBI_RNG_CFG_INTERRUPT_SENT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_INTERRUPT_SENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_INTERRUPT_SENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_BIST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_BIST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_BIST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_BIST_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_BIST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_BIST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_BIST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_BIST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_BIST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_BIST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_BIST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_BIST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_BIST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_BIST_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_BIST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_PBI_RNG_CFG_BIST_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_BIST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_BIST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_BIST_COMPLETE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_BIST_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_BIST_COMPLETE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_BIST_COMPLETE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_BIST_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_BIST_COMPLETE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_BIST_COMPLETE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_BIST_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_BIST_COMPLETE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_BIST_COMPLETE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_BIST_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_BIST_COMPLETE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_BIST_COMPLETE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_BIST_COMPLETE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_BIST_COMPLETE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_PBI_RNG_CFG_BIST_COMPLETE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_BIST_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_BIST_COMPLETE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG0_BIST_FAIL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG0_BIST_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG0_BIST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG0_BIST_FAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG0_BIST_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG0_BIST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG0_BIST_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_RNG0_BIST_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG0_BIST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_RNG0_BIST_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_RNG0_BIST_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG0_BIST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_RNG0_BIST_FAIL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_RNG0_BIST_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG0_BIST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_PBI_RNG_CFG_RNG0_BIST_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_RNG0_BIST_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG0_BIST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG1_BIST_FAIL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG1_BIST_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG1_BIST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG1_BIST_FAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG1_BIST_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG1_BIST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG1_BIST_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_RNG1_BIST_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG1_BIST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_RNG1_BIST_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_RNG1_BIST_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG1_BIST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_RNG1_BIST_FAIL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_RNG1_BIST_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG1_BIST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_PBI_RNG_CFG_RNG1_BIST_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_RNG1_BIST_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG1_BIST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH,
           NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH,
           NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH,
           NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_BIST_BIT_FAIL_TH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG0_INJ_CONTINOUS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG1_INJ_CONTINOUS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_ST2_RESET_PERIOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_ST2_RESET_PERIOD,
           NX_PBI_RNG_CFG_ST2_RESET_PERIOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_ST2_RESET_PERIOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_ST2_RESET_PERIOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_ST2_RESET_PERIOD,
           NX_PBI_RNG_CFG_ST2_RESET_PERIOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_ST2_RESET_PERIOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_ST2_RESET_PERIOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_ST2_RESET_PERIOD,
           NX_PBI_RNG_CFG_ST2_RESET_PERIOD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_ST2_RESET_PERIOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RRN_BYPASS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_MASK_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_SAMPTEST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_SAMPTEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_SAMPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_SAMPTEST_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_SAMPTEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_SAMPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_SAMPTEST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_SAMPTEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_SAMPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_SAMPTEST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_SAMPTEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_SAMPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_SAMPTEST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_SAMPTEST_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_SAMPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_PBI_RNG_CFG_SAMPTEST_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_SAMPTEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_SAMPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_REPTEST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_REPTEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_REPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_REPTEST_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_REPTEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_REPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_REPTEST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_REPTEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_REPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_REPTEST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_REPTEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_REPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_REPTEST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_REPTEST_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_REPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_PBI_RNG_CFG_REPTEST_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_REPTEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_REPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_ADAPTEST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_ADAPTEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_ADAPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_ADAPTEST_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_ADAPTEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_ADAPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_ADAPTEST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_ADAPTEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_ADAPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_ADAPTEST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_ADAPTEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_ADAPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_ADAPTEST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_ADAPTEST_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_ADAPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_PBI_RNG_CFG_ADAPTEST_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_ADAPTEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_ADAPTEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_PACE_RATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_PACE_RATE,
           NX_PBI_RNG_CFG_PACE_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_PACE_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_PACE_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_PACE_RATE,
           NX_PBI_RNG_CFG_PACE_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_PACE_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_PACE_RATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_PACE_RATE,
           NX_PBI_RNG_CFG_PACE_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_PACE_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_CFG_RNG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_CFG_RNG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.setBit<NX_PBI_RNG_CFG_RNG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_RNG_CFG_RNG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return o_data.clearBit<NX_PBI_RNG_CFG_RNG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_CFG_RNG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.extractToRight<NX_PBI_RNG_CFG_RNG_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_PBI_RNG_CFG_RNG_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_CFG));
#endif
    return i_data.getBit<NX_PBI_RNG_CFG_RNG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_CFG_RNG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_RNG_ST2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_RNG_ST2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_RNG_ST2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_RNG_ST2;
#endif
    return fapi2::getScom(i_target, NX_PBI_RNG_ST2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_RNG_ST2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return fapi2::putScom(i_target, NX_PBI_RNG_ST2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0,
           NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0,
           NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0,
           NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1,
           NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1,
           NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1,
           NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_RRN_RNG1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0,
           NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0,
           NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0,
           NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1,
           NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1,
           NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1,
           NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST2_ADAPTEST_SOFT_FAIL_COUNT_CRN_RNG1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0,
           NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0,
           NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0,
           NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1,
           NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return o_data.insertFromRight<NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1,
           NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_RNG_ST2));
#endif
    return i_data.extractToRight<NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1,
           NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_RNG_ST2_REPTEST_SOFT_FAIL_COUNT_RNG1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB;
#endif
    return fapi2::getScom(i_target, NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB));
#endif
    return fapi2::putScom(i_target, NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_LPID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_LPID,
           NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_LPID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_LPID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_LPID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_LPID,
           NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_LPID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_LPID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_LPID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_LPID,
           NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_LPID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_LPID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_PID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_PID,
           NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_PID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_PID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_PID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_PID,
           NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_PID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_PID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_PID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_PID,
           NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_PID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_PID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_TID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_TID,
           NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_TID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_TID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_TID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_TID,
           NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_TID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_TID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_TID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_TID,
           NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_TID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_TID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB));
#endif
    return o_data.setBit<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB));
#endif
    return o_data.clearBit<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB));
#endif
    return i_data.getBit<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_ASB_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL;
#endif
    return fapi2::getScom(i_target, NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL));
#endif
    return fapi2::putScom(i_target, NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET,
           NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET,
           NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET,
           NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_QUEUED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_QUEUED,
           NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_QUEUED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_QUEUED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_QUEUED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_QUEUED,
           NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_QUEUED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_QUEUED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_QUEUED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_QUEUED,
           NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_QUEUED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_QUEUED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX,
           NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX,
           NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX,
           NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR;
#endif
    return fapi2::getScom(i_target, NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR));
#endif
    return fapi2::putScom(i_target, NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR,
           NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR,
           NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR,
           NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR_SIZE,
           NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR_SIZE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR_SIZE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR));
#endif
    return o_data.insertFromRight<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR_SIZE,
           NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR_SIZE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR));
#endif
    return i_data.extractToRight<NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR_SIZE,
           NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NX_PBI_UMAC_EFT_LO_PRIOR_RCV_FIFO_BAR_EFT_LO_PRIORITY_RCV_FIFO_BAR_SIZE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_EN_DOB_ECC_ERR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_EN_DOB_ECC_ERR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_EN_DOB_ECC_ERR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_EN_DOB_ECC_ERR_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_EN_DOB_ECC_ERR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_EN_DOB_ECC_ERR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_EN_DOB_ECC_ERR_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_EN_DOB_ECC_ERR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_MAILBOX_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_MAILBOX_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_MAILBOX_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_MAILBOX_DATA_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_MAILBOX_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_MAILBOX_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MAILBOX_DATA_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_MAILBOX_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_PMU2_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PMU2_CNPM_COUNTER;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_PMU2_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PMU2_CNPM_COUNTER;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_PMU2_CNPM_COUNTER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_PMU2_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PMU2_CNPM_COUNTER));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_PMU2_CNPM_COUNTER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_PTL_FIR_REG_RWX(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PTL_FIR_REG_RWX;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_PTL_FIR_REG_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PTL_FIR_REG_RWX;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_PTL_FIR_REG_RWX, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_PTL_FIR_REG_RWX(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_PTL_FIR_REG_RWX, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_PTL_FIR_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PTL_FIR_REG_WOX_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_PTL_FIR_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PTL_FIR_REG_WOX_AND;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_PTL_FIR_REG_WOX_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_PTL_FIR_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PTL_FIR_REG_WOX_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_PTL_FIR_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PTL_FIR_REG_WOX_OR;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_PTL_FIR_REG_WOX_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_PTL_FIR_REG_WOX_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_PTL_FIR_REG_WOX_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RWX, PB_PTLSCOM10_PTL_FIR_REG_WOX_AND,
                           PB_PTLSCOM10_PTL_FIR_REG_WOX_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return o_data.setBit<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return i_data.getBit<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT,
           PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT,
           PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT,
           PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC0_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return o_data.setBit<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return i_data.getBit<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT,
           PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT,
           PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT,
           PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DOB_VC1_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT,
           PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT,
           PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT,
           PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_HI_BACKOFF_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT,
           PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT,
           PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT,
           PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_LO_BACKOFF_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT,
           PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT,
           PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT,
           PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_VC_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return o_data.setBit<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return i_data.getBit<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_LINK23_DIB_RTAG_DATA_ASY_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2,
           PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2,
           PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2,
           PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM10_TL_LINK_DATA_23_CFG_REG_DIBDOB23_SP_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_MAILBOX_30_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_MAILBOX_30_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_MAILBOX_30_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_MAILBOX_30_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_MAILBOX_30_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_MAILBOX_30_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_MAILBOX_30_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_MAILBOX_30_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_MAILBOX_31_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_MAILBOX_31_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_MAILBOX_31_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_MAILBOX_31_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_MAILBOX_31_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_MAILBOX_31_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_MAILBOX_31_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_MAILBOX_31_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_PMU0_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_PMU0_CNPM_COUNTER;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_PMU0_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_PMU0_CNPM_COUNTER;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_PMU0_CNPM_COUNTER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_PMU0_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PMU0_CNPM_COUNTER));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_PMU0_CNPM_COUNTER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_PSAVE01_MISC_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_PSAVE01_MISC_CFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_PSAVE01_MISC_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_PSAVE01_MISC_CFG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_PSAVE01_MISC_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_PSAVE01_MISC_CFG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_PSAVE01_MISC_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUC,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUC,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUC,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUC,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUC,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUC,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUT,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUT,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUT,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_LUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUT,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUT,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUT,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_HUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_SPARE,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_SPARE,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_SPARE,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_HALF_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUC,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUC,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUC,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUC,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUC,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUC,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUT,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUT,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUT,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_LUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUT,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUT,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUT,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_HUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_SPARE,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_SPARE,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_SPARE,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_QTR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE01_MISC_CFG_WSIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_WSIZE,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_WSIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_WSIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PSAVE01_MISC_CFG_WSIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_WSIZE,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_WSIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_WSIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PSAVE01_MISC_CFG_WSIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PSAVE01_MISC_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PSAVE01_MISC_CFG_WSIZE,
           PB_PTLSCOM23_PSAVE01_MISC_CFG_WSIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PSAVE01_MISC_CFG_WSIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return o_data.setBit<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return i_data.getBit<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT,
           PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT,
           PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT,
           PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return o_data.setBit<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return i_data.getBit<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT,
           PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT,
           PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT,
           PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT,
           PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT,
           PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT,
           PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT,
           PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT,
           PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT,
           PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT,
           PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT,
           PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT,
           PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return o_data.setBit<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return i_data.getBit<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2,
           PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2,
           PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2,
           PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_CFG_TLPM_MUX1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_CFG_TLPM_MUX1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_CFG_TLPM_MUX1_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_CFG_TLPM_MUX1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_CFG_TLPM_MUX1_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_CFG_TLPM_MUX1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_0,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_0,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_0,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_1,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_1,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_1,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_2,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_2,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_2,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_3,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_3,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_3,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_4,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_4,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_4,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_5,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_5,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_5,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_6,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_6,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_6,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_7,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_7,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_7,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_8,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_8,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_8,
           PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_8_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_LINK_EVENT_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_ALT_EVENTS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_ALT_EVENTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_ALT_EVENTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_ALT_EVENTS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_ALT_EVENTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_ALT_EVENTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_ALT_EVENTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return o_data.setBit<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_ALT_EVENTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_ALT_EVENTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_ALT_EVENTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_ALT_EVENTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_ALT_EVENTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_ALT_EVENTS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_ALT_EVENTS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_ALT_EVENTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_CFG_TLPM_MUX1_REG_ALT_EVENTS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX1_REG));
#endif
    return i_data.getBit<PB_PTLSCOM45_CFG_TLPM_MUX1_REG_ALT_EVENTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX1_REG_ALT_EVENTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_CFG_TLPM_MUX2_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_CFG_TLPM_MUX2_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_CFG_TLPM_MUX2_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_CFG_TLPM_MUX2_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_CFG_TLPM_MUX2_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_CFG_TLPM_MUX2_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX2_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_CFG_TLPM_MUX2_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX2_REG_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX2_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX2_REG_9,
           PB_PTLSCOM45_CFG_TLPM_MUX2_REG_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX2_REG_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX2_REG_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX2_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX2_REG_9,
           PB_PTLSCOM45_CFG_TLPM_MUX2_REG_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX2_REG_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_MUX2_REG_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX2_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_MUX2_REG_9,
           PB_PTLSCOM45_CFG_TLPM_MUX2_REG_9_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX2_REG_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX2_REG_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX2_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX2_REG_10,
           PB_PTLSCOM45_CFG_TLPM_MUX2_REG_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX2_REG_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX2_REG_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX2_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX2_REG_10,
           PB_PTLSCOM45_CFG_TLPM_MUX2_REG_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX2_REG_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_MUX2_REG_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX2_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_MUX2_REG_10,
           PB_PTLSCOM45_CFG_TLPM_MUX2_REG_10_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX2_REG_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX2_REG_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX2_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX2_REG_11,
           PB_PTLSCOM45_CFG_TLPM_MUX2_REG_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX2_REG_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX2_REG_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX2_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX2_REG_11,
           PB_PTLSCOM45_CFG_TLPM_MUX2_REG_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX2_REG_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_MUX2_REG_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX2_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_MUX2_REG_11,
           PB_PTLSCOM45_CFG_TLPM_MUX2_REG_11_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX2_REG_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX2_REG_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX2_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX2_REG_12,
           PB_PTLSCOM45_CFG_TLPM_MUX2_REG_12_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX2_REG_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX2_REG_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX2_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX2_REG_12,
           PB_PTLSCOM45_CFG_TLPM_MUX2_REG_12_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX2_REG_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_MUX2_REG_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX2_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_MUX2_REG_12,
           PB_PTLSCOM45_CFG_TLPM_MUX2_REG_12_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX2_REG_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX2_REG_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX2_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX2_REG_13,
           PB_PTLSCOM45_CFG_TLPM_MUX2_REG_13_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX2_REG_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX2_REG_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX2_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX2_REG_13,
           PB_PTLSCOM45_CFG_TLPM_MUX2_REG_13_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX2_REG_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_MUX2_REG_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX2_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_MUX2_REG_13,
           PB_PTLSCOM45_CFG_TLPM_MUX2_REG_13_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX2_REG_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX2_REG_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX2_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX2_REG_14,
           PB_PTLSCOM45_CFG_TLPM_MUX2_REG_14_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX2_REG_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX2_REG_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX2_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX2_REG_14,
           PB_PTLSCOM45_CFG_TLPM_MUX2_REG_14_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX2_REG_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_MUX2_REG_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX2_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_MUX2_REG_14,
           PB_PTLSCOM45_CFG_TLPM_MUX2_REG_14_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX2_REG_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX2_REG_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX2_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX2_REG_15,
           PB_PTLSCOM45_CFG_TLPM_MUX2_REG_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX2_REG_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_CFG_TLPM_MUX2_REG_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX2_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_CFG_TLPM_MUX2_REG_15,
           PB_PTLSCOM45_CFG_TLPM_MUX2_REG_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX2_REG_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_CFG_TLPM_MUX2_REG_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_CFG_TLPM_MUX2_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_CFG_TLPM_MUX2_REG_15,
           PB_PTLSCOM45_CFG_TLPM_MUX2_REG_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_CFG_TLPM_MUX2_REG_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_PERFTRACE_CFG_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PERFTRACE_CFG_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_PERFTRACE_CFG_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PERFTRACE_CFG_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_PERFTRACE_CFG_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_PERFTRACE_CFG_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_PERFTRACE_CFG_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.setBit<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return i_data.getBit<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_FIXED_WINDOW_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_FIXED_WINDOW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_FIXED_WINDOW_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_FIXED_WINDOW_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_FIXED_WINDOW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_FIXED_WINDOW_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_FIXED_WINDOW_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.setBit<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_FIXED_WINDOW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_FIXED_WINDOW_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_FIXED_WINDOW_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_FIXED_WINDOW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_FIXED_WINDOW_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_FIXED_WINDOW_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_FIXED_WINDOW_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_FIXED_WINDOW_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_FIXED_WINDOW_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return i_data.getBit<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_FIXED_WINDOW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_FIXED_WINDOW_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_PRESCALE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_PRESCALE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_PRESCALE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_PRESCALE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_PRESCALE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_PRESCALE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_PRESCALE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.setBit<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_PRESCALE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_PRESCALE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_PRESCALE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_PRESCALE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_PRESCALE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_PRESCALE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_PRESCALE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_PRESCALE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_PRESCALE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return i_data.getBit<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_PRESCALE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_PRESCALE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.setBit<PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return i_data.getBit<PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.setBit<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return i_data.getBit<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_FIXED_WINDOW_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_FIXED_WINDOW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_FIXED_WINDOW_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_FIXED_WINDOW_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_FIXED_WINDOW_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_FIXED_WINDOW_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_FIXED_WINDOW_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.setBit<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_FIXED_WINDOW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_FIXED_WINDOW_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_FIXED_WINDOW_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_FIXED_WINDOW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_FIXED_WINDOW_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_FIXED_WINDOW_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_FIXED_WINDOW_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_FIXED_WINDOW_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_FIXED_WINDOW_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return i_data.getBit<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_FIXED_WINDOW_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_FIXED_WINDOW_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_PRESCALE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_PRESCALE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_PRESCALE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_PRESCALE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_PRESCALE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_PRESCALE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_PRESCALE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.setBit<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_PRESCALE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_PRESCALE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_PRESCALE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_PRESCALE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_PRESCALE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_PRESCALE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_PRESCALE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_PRESCALE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_PRESCALE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return i_data.getBit<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_PRESCALE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_PRESCALE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.setBit<PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return i_data.getBit<PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_TSPARE7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_SELECT,
           PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_SELECT,
           PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_SELECT,
           PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_HI_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_SELECT,
           PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_SELECT,
           PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PERFTRACE_CFG_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_SELECT,
           PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PERFTRACE_CFG_REG_ERFTRACE_LO_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET,
           PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET,
           PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET,
           PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET,
           PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET,
           PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET,
           PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT,
           PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT,
           PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT,
           PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT,
           PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT,
           PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT,
           PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_CFG_TLPM_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_CFG_TLPM_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_CFG_TLPM_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_CFG_TLPM_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_CFG_TLPM_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_CFG_TLPM_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_CFG_TLPM_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.setBit<PB_PTLSCOM67_CFG_TLPM_REG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_CFG_TLPM_REG_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM67_CFG_TLPM_REG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_CFG_TLPM_REG_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.getBit<PB_PTLSCOM67_CFG_TLPM_REG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_RESET_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_RESET_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_RESET_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_RESET_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_RESET_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.setBit<PB_PTLSCOM67_CFG_TLPM_REG_RESET_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_CFG_TLPM_REG_RESET_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM67_CFG_TLPM_REG_RESET_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_RESET_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_RESET_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_CFG_TLPM_REG_RESET_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.getBit<PB_PTLSCOM67_CFG_TLPM_REG_RESET_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_COUNTER_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_COUNTER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_COUNTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_COUNTER_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_COUNTER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_COUNTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_COUNTER_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.setBit<PB_PTLSCOM67_CFG_TLPM_REG_COUNTER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_COUNTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_CFG_TLPM_REG_COUNTER_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM67_CFG_TLPM_REG_COUNTER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_COUNTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_COUNTER_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_COUNTER_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_COUNTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_CFG_TLPM_REG_COUNTER_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.getBit<PB_PTLSCOM67_CFG_TLPM_REG_COUNTER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_COUNTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.setBit<PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.getBit<PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.setBit<PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.getBit<PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_GLOBAL_PMISC_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_EXTERNAL_FREEZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_EXTERNAL_FREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_EXTERNAL_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_EXTERNAL_FREEZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_EXTERNAL_FREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_EXTERNAL_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_EXTERNAL_FREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.setBit<PB_PTLSCOM67_CFG_TLPM_REG_EXTERNAL_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_EXTERNAL_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_CFG_TLPM_REG_EXTERNAL_FREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.clearBit<PB_PTLSCOM67_CFG_TLPM_REG_EXTERNAL_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_EXTERNAL_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_EXTERNAL_FREEZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_EXTERNAL_FREEZE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_EXTERNAL_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM67_CFG_TLPM_REG_EXTERNAL_FREEZE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.getBit<PB_PTLSCOM67_CFG_TLPM_REG_EXTERNAL_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_EXTERNAL_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_0_1_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_0_1_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_0_1_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_0_1_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_0_1_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_0_1_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_0_1_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_0_1_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_0_1_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_0_1_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_0_1_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_0_1_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_2_3_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_2_3_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_2_3_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_2_3_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_2_3_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_2_3_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_2_3_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_2_3_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_2_3_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_2_3_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_2_3_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_2_3_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_4_5_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_4_5_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_4_5_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_4_5_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_4_5_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_4_5_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_4_5_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_4_5_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_4_5_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_4_5_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_4_5_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_4_5_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_6_7_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_6_7_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_6_7_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_6_7_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_6_7_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_6_7_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_6_7_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_6_7_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_6_7_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_6_7_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_6_7_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_6_7_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_8_9_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_8_9_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_8_9_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_8_9_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_8_9_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_8_9_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_8_9_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_8_9_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_8_9_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_8_9_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_8_9_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_8_9_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_10_11_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_10_11_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_10_11_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_10_11_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_10_11_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_10_11_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_10_11_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_10_11_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_10_11_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_10_11_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_10_11_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_10_11_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_12_13_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_12_13_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_12_13_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_12_13_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_12_13_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_12_13_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_12_13_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_12_13_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_12_13_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_12_13_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_12_13_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_12_13_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_14_15_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_14_15_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_14_15_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_14_15_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_14_15_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_14_15_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_14_15_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_14_15_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_14_15_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_14_15_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_14_15_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_14_15_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_16_17_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_16_17_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_16_17_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_16_17_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_16_17_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_16_17_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_16_17_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_16_17_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_16_17_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_16_17_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_16_17_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_16_17_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_18_19_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_18_19_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_18_19_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_18_19_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_18_19_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_18_19_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_18_19_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_18_19_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_18_19_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_18_19_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_18_19_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_18_19_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_20_21_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_20_21_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_20_21_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_20_21_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_20_21_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_20_21_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_20_21_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_20_21_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_20_21_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_20_21_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_20_21_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_20_21_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_22_23_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_22_23_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_22_23_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_22_23_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_22_23_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_22_23_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_22_23_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_22_23_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_22_23_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_22_23_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_22_23_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_22_23_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_24_25_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_24_25_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_24_25_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_24_25_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_24_25_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_24_25_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_24_25_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_24_25_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_24_25_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_24_25_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_24_25_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_24_25_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_26_27_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_26_27_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_26_27_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_26_27_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_26_27_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_26_27_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_26_27_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_26_27_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_26_27_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_26_27_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_26_27_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_26_27_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_28_29_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_28_29_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_28_29_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_28_29_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_28_29_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_28_29_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_28_29_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_28_29_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_28_29_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_28_29_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_28_29_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_28_29_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_30_31_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_30_31_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_30_31_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_30_31_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_30_31_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_30_31_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_30_31_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_30_31_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_30_31_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_30_31_OP,
           PB_PTLSCOM67_CFG_TLPM_REG_30_31_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_30_31_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU0,
           PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU0,
           PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU0,
           PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU1,
           PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU1,
           PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU1,
           PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU2,
           PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU2,
           PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU2,
           PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU3,
           PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU3,
           PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU3,
           PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_CASCADE_PMU3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_SPARE,
           PB_PTLSCOM67_CFG_TLPM_REG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_CFG_TLPM_REG_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_CFG_TLPM_REG_SPARE,
           PB_PTLSCOM67_CFG_TLPM_REG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_CFG_TLPM_REG_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_CFG_TLPM_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_CFG_TLPM_REG_SPARE,
           PB_PTLSCOM67_CFG_TLPM_REG_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_CFG_TLPM_REG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_MAILBOX_10_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_MAILBOX_10_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_MAILBOX_10_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_MAILBOX_10_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_MAILBOX_10_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_MAILBOX_10_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_10_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_MAILBOX_10_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_MAILBOX_11_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_MAILBOX_11_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_MAILBOX_11_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_MAILBOX_11_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_MAILBOX_11_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_MAILBOX_11_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_11_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_MAILBOX_11_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}



}
}

#endif
